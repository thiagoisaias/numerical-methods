s
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
    f = open('matrix.txt','r')
    matrix = np.array([], dtype = np.float64)
    matrix = [map(np.float64,line.split(',')) for line in f]
    return matrix

def verify_error(error,vector1,vector2): # True -> Stop False ->Continue
    #aux = vector1 - vector2
    #aux = np.power(aux,2)
    aux = np.absolute(vector1) - np.absolute(vector2)
    aux = np.absolute(aux)

    for element in aux:
        if element > error:
            return True
    return False

def householder(col,i,n):
    vector = col[i+1:n]
    cv = euclidean_norm(vector)
    nvector = vector
    if(vector[0]>0):
        nvector[0] = nvector[0] + cv
    else:
        nvector[0] = nvector[0] - cv
    cn = euclidean_norm(nvector)
    n = zeros(n)

    return np.identity(n) - 2*np.dot(n,n.T)

def tridiagonal_loop():
    matrix = file_matrix()
    n = len(matrix)
    house_matrix = np.identity(4)
    aux = matrix
    for i in range(0,n-3):
        q_matrix = householder(aux[:,i],i,n)
        house_matrix = np.dot(house_matrix,q_matrix)
        aux = np.dot(np.dot(q_matrix,aux),q_matrix) #QAQ
    return aux

tridiagonal_loop()
