# rekursiivinen kertoma funktio, sisään kokonaisluku joka suurempi kuin 1, ulos luku
def kertoma(num, perse=1):
    if num == 0:
        return perse
    else:
        return kertoma(num-1, num*perse)

def main():
    luku = str(input("Anna luku josta haluat laskea kertoman: "))

    # perus virhetarkastelu
    try:
        luku = int(luku)
        if luku < 0:
            print("Kertomaa ei voi laskea negatiivisesta luvusta")
            return
        
        vastaus = kertoma(luku)
        print(str(luku) + "! = " + str(vastaus))
        
    except:
        print("Syöte ei ollut kokonais luku")

main()