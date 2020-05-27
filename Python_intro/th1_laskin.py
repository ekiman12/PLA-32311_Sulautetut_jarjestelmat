def main():
    # ekan luvun syöttö ja tarkistus
    luku1 = input("Anna ensimmainen luku: ")
    try:
        luku1 = int(luku1)
    except:
        print("Syöte ei ollut numero")
        return

    # syötteen kommentointi
    if luku1 < 50:
        print(str(luku1) + " oli pienempi kuin 50")
    else:
        print(str(luku1) + " oli suurempit tai yhtäsuuri kuin 50")

    # toisen luvun syöttö ja tarkistus
    luku2 = input("Anna toinen luku: ")
    try:
        luku2 = int(luku2)
    except:
        print("Syöte ei ollut numero")
        return
    
    # lopputulema
    print("Tulos on:\n" + str(luku1+luku2))

main()