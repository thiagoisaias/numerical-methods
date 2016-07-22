# -*- coding: utf-8 -*-
#Idêntica à tarefa T09, exceto que o código deve determinar o autovalor (Lambda_n - Menor autovalor em módulo)
#e seu autovetor correspondente (Phi_n).

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
    f = open('./data/ap.txt','r')
    matrix = np.array([], dtype = np.float64)
    matrix = [map(np.float64,line.split(',')) for line in f]
    return matrix

def inverse_power_method(precision):
    matrix = file_matrix()
    n = len(matrix)
    eigenvec = np.ones(n)
    auxvec = np.zeros(n)
    domvec = np.ones(n)

    while(verify_error(precision,eigenvec,auxvec)):
        auxvec = eigenvec
        domvec = np.dot(matrix,eigenvec)
        eigenvec = np.dot(np.linalg.inv(matrix),eigenvec)/euclidean_norm(np.dot(np.linalg.inv(matrix),eigenvec))

    eigenvalue = rayleigh_quotient(matrix,eigenvec)
    #eigenvec = domvec/domvec[n-1]

    print '\nThe smallest Eigenvalue is: '
    print eigenvalue
    print '\nEigenvector: '
    print eigenvec
    print '\n'


precision = input("Precision: ")
inverse_power_method(precision)
