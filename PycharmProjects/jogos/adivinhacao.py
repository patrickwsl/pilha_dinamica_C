import random


def jogar():
    print("*********************************")
    print("Bem vindo ao jogo de Adivinhação!")
    print("*********************************")

    numero_secreto = random.randrange(1,101)
    pontos = 1000

    print("Qual o nivel de dificuldade?")
    print("(1) Facil (2) Médio (3) Difícil")

    nivel = int(input("Defina o nível: "))

    if(nivel == 1):
        total_tentativas = 20
    elif(nivel == 2):
        total_tentativas = 10
    else:
        total_tentativas = 5

    for rodada in range(1, total_tentativas + 1):
        print("Tentativa {} de {}".format(rodada, total_tentativas))
        chute_str = input("Digite um numero entre 1 e 100: ")
        print("Você digitou", chute_str)
        chute = int(chute_str)

        if(chute < 1 or chute > 100):
            print("Você deve digitar um numero entre 1 e 100!")
            continue

        acertou = chute == numero_secreto
        maior   = chute > numero_secreto
        menor   = chute < numero_secreto

        if(acertou):
            print("Você acertou e fez {} pontos!".format(pontos))
            break
        else:
            if(maior):
                print("Você errou! O seu chute foi maior do que o numero secreto")
            elif menor:
                print("Você errou! O seu chute foi menor do que o numero secreto")
            pontos_perdidos = numero_secreto - chute
            abs(pontos_perdidos)
            pontos = pontos - pontos_perdidos

    print("Fim do jogo")


if(__name__ == "__main__"):
    jogar()