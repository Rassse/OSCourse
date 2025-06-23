def bittisumma(a, b):
    summa = a
    while a != 0 | b != 0:
        # Deepseek auttoi tajuamaan, että muistibitille ei tarvitse olla if lausetta, kuten aikaisemmin minulla oli, vaan se tallennetaan muuttujaan.
        muistibitti = summa & b
        summa = summa ^ b
        b = muistibitti << 1
    print(summa)
    return summa

bittisumma(100, 15)
