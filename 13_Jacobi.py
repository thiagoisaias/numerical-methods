 # -*- coding: utf-8 -*-
# Escreva e teste um programa que usa o método de Jacobi para transformar uma matriz simétrica A,
# dada como entrada, em uma matriz DIAGONAL. O programa deve ler a matriz e uma tolerância
# a partir de um arquivo e imprimir: a matriz de entrada, a matriz diagonal e a matriz de Jacobi.
# Teste se as colunas da matriz de Jacobi são autovetores da matriz de entrada.

import numpy as np
import math
np.set_printoptions(precision=6,suppress=True)

def euclidean_norm(vector):
    total = 0
    for component in vector:
        total += pow(component,2)
    return math.sqrt(total)

def file_matrix():
    matrix = np.loadtxt('matrix2.txt', dtype = np.float64, delimiter = ',')
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

def build(jj, ij, ii, i, j, n):
	R_matrix = np.identity(n)
	theta = 0
	if ii == jj:
		theta = math.pi/4
	else:
		theta = (math.atan(2*ij/(jj-ii)))/2

	R_matrix[j,j] =	math.cos(theta)
	R_matrix[j,i] = -math.sin(theta)
	R_matrix[i,j] = math.sin(theta)
	R_matrix[i,i] = math.cos(theta)

	return R_matrix

def process_eigenvectors(jacobimatrix,n):
    #jacobimatrix[:,0] = jacobimatrix[:,0]/jacobimatrix[n-1,0]
    #jacobimatrix[:,1] = jacobimatrix[:,1]/jacobimatrix[n-1,1]
    #jacobimatrix[:,2] = jacobimatrix[:,2]/jacobimatrix[n-1,2]

    #cada coluna da jacobimatrix é um autovetor da matrix original.
    #essa funcao normaliza o vetor, dividindo a coluna pelo ultimo elemento
    for i in range(n):
        jacobimatrix[:,i] = jacobimatrix[:,i]/jacobimatrix[n-1,i]
    return jacobimatrix

def jacobi(error):
    matrix = file_matrix()
    n = len(matrix)
    J = np.identity(n) #matriz de jacobi
    R = np.identity(n) #matriz de rotacao
    aux = matrix #matriz que será modificada

    while(verify_error(error,aux)):
        for j in range(0,n-1):
            for i in range(j+1,n):
                R = build(aux[j,j],aux[i,j],aux[i,i],i,j,n)
                aux = R.T.dot(aux).dot(R) #J'AJ
                J = J.dot(R) #Acumular o produto das matrizes de rotacao para encontrar os autovetores


    print "Original Matrix: "
    print matrix
    print "\n"
    print "Jacobi Matrix"
    print J
    print "\n"
    print "Normalized Eigenvectors"
    print process_eigenvectors(J,n)
    print "\n"
    print "Diagonal Matrix"
    print aux

error = input("Precision: ")
jacobi(error)
