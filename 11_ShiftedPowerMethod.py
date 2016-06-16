 # -*- coding: utf-8 -*-
#Requisitos:
#1) Entrada e saída em arquivo;
#2) Dados de entrada: Matriz A e tolerância para parada
#3) O código deve usar o teorema dos discos de Gerschgorin e definir a
#faixa que contém os autovalores reais e, em seguida percorrer a faixa
#em sentido crescente, atribuindo valores de mu e tentando achar o maior número
#de autovalores e seus autovalores correspondentes
#(Por exemplo, se a faixa for de 1 a 20, divida a faixa em 5n valores discretos (mu)
#e procure o autovalor próximo a dada mu.

import numpy as np
from math import sqrt

def euclidean_norm(vector):
    total = 0
    for component in vector:
        total += pow(component,2)
    return sqrt(total)

def rayleigh_quotient(matrix,eigenvector):
    aux = np.dot(matrix,eigenvector)
    return np.dot(aux,eigenvector) / np.dot(eigenvector,eigenvector)

def verify_error(error,vector1,vector2): # True -> Stop False ->Continue
    aux = np.absolute(vector1) - np.absolute(vector2)
    aux = np.absolute(aux)

    for element in aux:
        if element > error:
            return True
    return False

def file_matrix():
    f = open('matrix.txt','r')
    matrix = np.array([], dtype = np.float64)
    matrix = [map(np.float64,line.split(',')) for line in f]
    return matrix

def find_interval(matrix):
    for i in range(len(matrix)):


def shifted_method(precision):
    matrix = file_matrix()
    n = len(matrix)
    eigenvec = np.ones((n), dtype = np.float64)
    auxvec = np.zeros((n), dtype = np.float64)
    domvec = np.ones((n), dtype = np.float64)

    while(verify_error(precision,eigenvec,auxvec)):
        #auxvec = eigenvec
        #domvec = np.dot(matrix,eigenvec) A matrix usada sera (A - alfa*I)
        #Como escolher o alfa(shift)?

    eigenvalue = rayleigh_quotient(matrix,eigenvec)
    eigenvec = domvec/domvec[n-1]

    print '\nThe Dominant Eigenvalue is: '
    print eigenvalue
    print '\nEigenvector: '
    print eigenvec
    print '\n'


precision = input("Precision: ")
shifted_method(precision)
