def toh(n, src, dest, aux):
    if(n == 0):
        return
    toh(n-1, src, aux, dest)
    print("move disk " + str(n)+" from disk "+str(src)+" to disk "+str(dest))
    toh(n-1, aux, dest, src)



toh(3, 'A', 'C', 'B')


