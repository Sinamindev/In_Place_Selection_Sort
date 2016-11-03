#!/usr/bin/env python3
import time, sys

#In place selections sort algorithm
def in_place_selection_sort(L):
    for k in range(len(L)-1):
        least = k
        for i in range(k+1, len(L)):
            if L[i] < L[least]:
                least = i
        #swap elements
        L[k], L[least] = L[least], L[k]
    return L
        
def main():
    text = []
    sample = []
    
    file = open('beowulf.txt')
    n = input("Enter value for n: ")
    
    with file as fh:
        if(fh):
            for i in fh:
                text.append(i.strip())
    
    for k in range(int(n)):
        sample.append(text[k])
    
    for j in range(10):
        print(j+1, ' ' , sample[j])
        
    print('\nselection sort...')
    print('Sorted:')
    
    start = time.perf_counter()
    sorted_text = in_place_selection_sort(sample)
    end = time.perf_counter()
    
    for j in range(10):
        print(j+1, ' ' , sorted_text[j])

    print('\nElapsed time: ' +str(end-start)+ ' seconds')

if __name__ == '__main__':
    main()
