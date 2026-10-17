#include <iostream>
#include <string>

using namespace std;

struct Camada{
    string nome;
    char matriz[3][3];
    bool visivel;
};

struct Sprite{
    Camada camada[4];
};

void renderizarSprite(const Sprite& sprite){
    char matrizFinal[3][3];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matrizFinal[i][j] = ' ';
        }
    }

    for (int c = 0; c < 4; c++){
        if (sprite.camada[c].visivel){
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if (sprite.camada[c].matriz[i][j] != ' '){
                        matrizFinal[i][j] = sprite.camada[c].matriz[i][j];
                    }
                }
            }
        }
    }

    cout << "\nCamadas -> ";
    for (int c = 0; c < 4; c++){
        cout << sprite.camada[c].nome << "["
             << (sprite.camada[c].visivel ? "ON" : "off") << "]  ";
    }
    cout << "\n";

    cout << "+------------+\n";
    cout << "| BONECO 3x3 |\n";
    cout << "+------------+\n";
    for (int i = 0; i < 3; i++){
        cout << "|   ";
        for (int j = 0; j < 3; j++){
            cout << matrizFinal[i][j];
            if (j < 2) cout << ' ';
        }
        cout << "    |\n";
    }
    cout << "+------------+\n";
}

int main()
{
    Sprite meuSprite;

    meuSprite.camada[0].nome = "Fundo";
    meuSprite.camada[0].visivel = true;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            meuSprite.camada[0].matriz[i][j] = '.';


    meuSprite.camada[1].nome = "Corpo";
    meuSprite.camada[1].visivel = true;
    string desenhoCorpo[3] = {
        " O ",
        "/|\\",
        "/ \\"
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            meuSprite.camada[1].matriz[i][j] = desenhoCorpo[i][j];


    meuSprite.camada[2].nome = "Armadura";
    meuSprite.camada[2].visivel = true;
    string desenhoArmadura[3] = {
        "   ",
        "<#>",
        "   "
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            meuSprite.camada[2].matriz[i][j] = desenhoArmadura[i][j];


    meuSprite.camada[3].nome = "Efeito Visual";
    meuSprite.camada[3].visivel = false;
    string desenhoVisual[3] = {
        "* *",
        "   ",
        " * "
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            meuSprite.camada[3].matriz[i][j] = desenhoVisual[i][j];

    renderizarSprite(meuSprite);

    string comando;
    while (true){
        cout << "\nDigite um comando (ex: 'ocultar armadura', 'exibir efeito' ou 'sair'): ";
        getline(cin, comando);

        if (comando == "sair"){
            cout << "Encerrando o programa...\n";
            break;
        }
        else if (comando == "ocultar armadura") {
            meuSprite.camada[2].visivel = false;
        }
        else if (comando == "exibir armadura") {
            meuSprite.camada[2].visivel = true;
        }
        else if (comando == "ocultar corpo") {
            meuSprite.camada[1].visivel = false;
        }
        else if (comando == "exibir corpo") {
            meuSprite.camada[1].visivel = true;
        }
        else if (comando == "ocultar fundo") {
            meuSprite.camada[0].visivel = false;
        }
        else if (comando == "exibir fundo") {
            meuSprite.camada[0].visivel = true;
        }
        else if (comando == "ocultar efeito") {
            meuSprite.camada[3].visivel = false;
        }
        else if (comando == "exibir efeito") {
            meuSprite.camada[3].visivel = true;
        }
        else {
            cout << "Comando nao reconhecido! Tente novamente.\n";
            continue;
        }

        renderizarSprite(meuSprite);
    }

    return 0;
}
