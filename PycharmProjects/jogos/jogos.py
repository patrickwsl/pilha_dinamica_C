import forca
import adivinhacao
def escolhe_jogo():
    print("*********************************")
    print("*******Escolha o seu jogo!*******")
    print("*********************************")

    print("(1) Forca (2) Adivinhação")

    jogo = int(input("Qual o jogo? "))

    if(jogo == 1):
        print("Você escolheu o jogo da Forca")
        forca.jogar()
    elif(jogo == 2):
        print("Você escolheu o jogo da Advinhação")
        adivinhacao.jogar()

if(__name__ == "__main__"):
    escolhe_jogo()