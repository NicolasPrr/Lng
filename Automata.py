import sys
def printMatriz(Matriz):
    for i in range(len(Matriz)):
        print(*Matriz[i])


def getW(estado, letra, matriz, alpha):
    #La funcion nos retorna  el estado dada la tabla de transicion en el estado "estado" para una entrada "letra" en el alfabeto
    #alpha
    pos = 0
    for i in range(len(alpha)):
        if alpha[i] == letra :
            return matriz[estado][i]


print("Ingrese el alfabeto separado por espacio")
Alpha=(sys.stdin.readline().strip().split(" "))
print("Ingrese el numero de estados")
T = int(sys.stdin.readline())
Matriz =  []
for i in range(T):
    Matriz.append([i])
    for j in range(len(Alpha) - 1):
        Matriz[i].append(None)


for i in range(T):
    print("ingrese las transiciones para el estado " + str(i))
    for j in range(len(Alpha)):
        print("ingrese el estado transicion para  " + str(Alpha[j]))
        S = int(sys.stdin.readline())
        Matriz[i][j] = S

print("Ingrese los estados finales")
estadosf=(sys.stdin.readline().strip().split(" "))
estadoa = 0


print("Ingrese el numero de pruebas ")
N = int(sys.stdin.readline())
for i in range(N):
    print("INGRESE LA PALABRA")
    S = (sys.stdin.readline())
    for j in range(len(S)):
        print("Estado actual q_" + str(estadoa)) #RECORRIDO DE ESTADOS
        estadoa = getW(estadoa,S[j], Matriz, Alpha)

    if estadoa in estadosf :
        print("ACEPTA LA PALARBA: " + S)
    else:
        print("NO LO ACEPTA: " + S)
