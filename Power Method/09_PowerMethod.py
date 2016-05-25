 # -*- coding: utf-8 -*-
#Implementar e testar o método da Potência Regular. O código deve ler:
#Uma matriz nxn a partir de um arquivo (ler n, ler a matriz),
#Ler um vetor inicial
#Ler uma tolerância (epsilon) a ser usada no critério de parada.
#O programa deve imprimir em arquivo o autovalor dominante (Lambda_1) e o autovetor correspondente (Phi_1).

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

def power_method(precision):
    #matrix = np.array([[1,2,0],[-2,1,2],[1,3,1]], dtype=np.float64)
    matrix = file_matrix()
    eigenvec = np.array([1,1,1] , dtype = np.float64)
    auxvec = np.array([0,0,0], dtype = np.float64)
    eigenvalue = 0

    while(verify_error(precision,eigenvec,auxvec)):
        auxvec = eigenvec
        eigenvec = np.dot(matrix,eigenvec)/euclidean_norm(np.dot(matrix,eigenvec))

    eigenvalue = rayleigh_quotient(matrix,eigenvec)

    print '\nThe Dominant Eigenvalue is: '
    print eigenvalue
    print 'An eigenvector associated with this eigenvalue: '
    print eigenvec

    print '\nTesting\n'
    print 'A.x'
    print np.dot(matrix,eigenvec)
    print "is equals to delta.x"
    print np.dot(eigenvalue,eigenvec)

#power_method()
precision = input("Precision: ")
power_method(precision)
