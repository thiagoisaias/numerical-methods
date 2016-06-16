 # -*- coding: utf-8 -*-
# Escreva e teste um programa que usa o método de Jacobi para transformar uma matriz simétrica A,
# dada como entrada, em uma matriz DIAGONAL. O programa deve ler a matriz e uma tolerância
# a partir de um arquivo e imprimir: a matriz de entrada, a matriz diagonal e a matriz de Jacobi.
# Teste se as colunas da matriz de Jacobi são autovetores da matriz de entrada.

import numpy as np
from math import sqrt

def euclidean_norm(vector):
    total = 0
    for component in vector:
        total += pow(component,2)
    return sqrt(total)

def file_matrix():
    f = open('matrix.txt','r')
    matrix = np.array([], dtype = np.float64)
    matrix = [map(np.float64,line.split(',')) for line in f]
    return matrix

def verify_error(error,matrix): # True -> Stop False ->Continue
    n = len(matrix)
    for i in range(0,n):
        if element > error:
            return True
    return False

def build(jj, ij, ii):
    return 2*ij/(jj-ii)

def jacobi():
    matrix = file_matrix()
    n = len(matrix)
    J = np.identity(n)
    aux = matrix

    for j in range(0,n-1)
        for i in range(j+1,n)
            J[i,j] = build(aux[j,j],aux[i,j],aux[i,i])
            aux = np.dot(np.dot(J.T,aux),J) #J'AJ
