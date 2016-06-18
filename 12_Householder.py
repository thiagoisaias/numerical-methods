 # -*- coding: utf-8 -*-
# Escreva e teste um programa que usa o método de Householder para transformar uma matriz simétrica A,
# dada como entrada, em uma matriz TRIDIAGONAL.
# O programa deve ler a matriz a partir de um arquivo e imprimir:
# a matriz de entrada, a matriz tridiagonal e a matriz de Householder.

import numpy as np
from math import sqrt

def euclidean_norm(vector):
    total = 0
    for component in vector:
        total += pow(component,2)
    return sqrt(total)

def file_matrix():
    matrix = np.loadtxt('matrix.txt', dtype = np.float64, delimiter = ',')
    #matrix = [map(np.float64,line.split(',')) for line in f]
    return matrix

def householder(col,i,n):
    vector = col[i+1:]
    cv = euclidean_norm(vector)
    nvector = vector
    if(vector[0]>0):
        nvector[0] = nvector[0] + cv
    else:
        nvector[0] = nvector[0] - cv
    cn = euclidean_norm(nvector)
    n_modified = nvector / cn
    nvector = np.append(np.zeros(i+1),n_modified)

    nvector = np.array([nvector]) #adding a new dimension (it is not possible to transpose a 1D array)
    nvector = nvector.T #transformando em vetor vertical

    return np.identity(n) - 2*np.dot(nvector,nvector.T)

def tridiagonal_loop():
    matrix = file_matrix()
    n = len(matrix)
    house_matrix = np.identity(n)
    aux = matrix

    for i in range(0,n-2):
        q_matrix = householder(aux[:,i],i,n)
        house_matrix = np.dot(house_matrix,q_matrix)
        aux = q_matrix.dot(aux).dot(q_matrix) #QAQ

    return 0
    print "Original Matrix: "
    print file_matrix()
    print "\n"
    print "Householder Matrix"
    print house_matrix
    print "\n"
    print "Tridiagonal Matrix"
    print aux

np.set_printoptions(precision=4,suppress=True)
tridiagonal_loop()
