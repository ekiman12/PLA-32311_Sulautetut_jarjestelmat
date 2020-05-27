TIEDOSTONIMI = "testi.txt"      # tiedostonimi
SANA_LKM = 3            # kysyttyjen sanojen määrä

# funktio syotteeenn kysyntaan
# sanamaara: sanoje lkm
# return: lista sanoista
def kysely(sanamaara):
    sanalista = []
    for i in range(sanamaara):
        sanalista.append( input("Anna sana " + str(i+1) + ": ") )
    return sanalista

# kirjoittaa tiedoston samaan kansioon, missä ohjelmaa ajetaan
# tiedostonimi: kirjoitettavan tiedoston nimi
def kirjoitaTiedosto(tiedostonimi, sanalista):
    tiedosto = open(tiedostonimi, "w+")

    for i in range(len(sanalista)):
        tiedosto.write(sanalista[i]+"\n")

    tiedosto.close()
    print("\nTiedosto kirjoitettu \n")
    return

# Lukee tiedoston
# tiedostonimi: tiedosto, josta tieto luetaan
def lueTiedosto(tiedostonimi):
    print("Luetaan tiedostoa \n")
    tiedosto = open(tiedostonimi,"r")

    sisalto = tiedosto.read()
    print(sisalto)
    print("Tiedosto luetu")
    return

def main():
    sanalista = kysely(SANA_LKM)
    kirjoitaTiedosto(TIEDOSTONIMI, sanalista)
    lueTiedosto(TIEDOSTONIMI)

main()
    