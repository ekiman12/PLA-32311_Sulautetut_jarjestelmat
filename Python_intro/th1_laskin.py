# rekursiivinen kertoma funktio, sisään kokonaisluku joka suurempi kuin 1, ulos luku
def kertoma(num):
    if num == 0:
        return 1
    else:
        return num*kertoma(num-1)

def main():
    luku = str(input("Anna luku josta haluat laskea kertoman: "))

        try int(luku)
            if luku < 0:
                print("Kertomaa ei voi laskea negatiivisesta luvusta")
                return
            vastaus = kertoma(luku)

            print(str(luku) + "! = " + str(vastaus))
            
        except Exception:
            print("Syöte ei ollut kokonais luku")

if __name__=="__main__":
    main()