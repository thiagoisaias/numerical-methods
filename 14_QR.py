 # -*- coding: utf-8 -*-
# Escreva e teste um programa que usa o método QR para transformar uma matriz simétrica A,
# dada como entrada, em uma matriz DIAGONAL. O programa deve ler a matriz e uma tolerância
# a partir de um arquivo e imprimir: a matriz de entrada, a matriz diagonal e a matriz de acumulada Q.
# Teste se as colunas da matriz de Q final são autovetores da matriz de entrada.

import numpy as np
import math
np.set_printoptions(precision=6,suppress=True)

def euclidean_norm(vector):
    total = 0
    for component in vector:
        total += pow(component,2)
    return math.sqrt(total)

def file_matrix():
    matrix = np.loadtxt('./data/matrix.txt', dtype = np.float64, delimiter = ',')
    return matrix

def verify_error(error,matrix): # True -> Continue False ->Stop
    n = len(matrix)
    total = 0
    for i in range(0,n):
        for j in range(0,n):
            if i!=j:
                total += pow(matrix[i,j],2) #soma do quadrado dos elementos fora da diagonal principal
    if math.sqrt(total) > error:
        return True
    else:
        return False

def build_rotationmatrix(ij, jj,i, j, n):
	R_matrix = np.identity(n)
	theta = 0
	if jj != 0:
		theta = math.atan(ij/jj)
	else:
		theta = math.pi/2

	R_matrix[j,j] =	math.cos(theta)
	R_matrix[j,i] = -math.sin(theta)
	R_matrix[i,j] = math.sin(theta)
	R_matrix[i,i] = math.cos(theta)

	return R_matrix

def process_eigenvectors(Q_matrix,n):
    #cada coluna da Q_matrix é um autovetor da matriz original.
    #essa funcao normaliza o vetor, dividindo a coluna pelo ultimo elemento
    for i in range(n):
        Q_matrix[:,i] = Q_matrix[:,i]/Q_matrix[n-1,i]
    return Q_matrix

#decompoe a matriz de entrada em um produto QR
#Q é ortonormal e R é uma matriz triangular superior
#Q.dot(R) == matrix(original)
def qr_decomposition(matrix):
    n = len(matrix)
    Q = np.identity(n)
    triangular_matrix = matrix
    theta = 0

    for j in range(0,n-1):
        for i in range(j+1,n):
            Q_modified = build_rotationmatrix(matrix[i,j],matrix[j,j],i,j,n)
            triangular_matrix = Q_modified.T.dot(matrix)
            Q = Q.dot(Q_modified)
            matrix = triangular_matrix

    return (Q,triangular_matrix)

def transformation(error):
    matrix = file_matrix()
    n = len(matrix)
    Q = np.identity(n)
    R = np.identity(n)
    aux = matrix

    while(verify_error(error,aux)):
        Q_modified,R = qr_decomposition(aux)
        aux = R.dot(Q_modified)
        Q = Q.dot(Q_modified) #acumular o produto de Q para encontrar os autovetores

    print "Original Matrix: "
    print file_matrix()
    print "\n"
    print "Q Matrix"
    print Q
    print "\n"
    print "Normalized Eigenvectors"
    print process_eigenvectors(Q,n)
    print "\n"
    print "Diagonal Matrix"
    print aux

error = input("Precision: ")
transformation(error)
