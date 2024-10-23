//** TRABALHO DO ALMIR - VERSÃO INICIAL PARA TESTES**
#include <iostream>
#include <string>
using namespace std;

int main() {

  //**Variáveis**
  const int n = 20;

  struct nolls {
    float peso;
    int id, idade;
    string nome, raca;
    char sexo;
  };

  nolls lst [n], val;
  int menu, final = -1, k, aux, srchid;
  bool sinal;
  char conf;
  string srchn;
  float srchp;

 //**Loop principal do menu**
 do {

  //**Menu inicial**
  cout << endl << "<--------Selecione a Opção desejada (1 a 15): " << endl;
  cout << endl << " 1. Inserir dados dos animais. " << endl;
  cout << " 2. Inserir na posição K+1. " << endl;
  cout << " 3. Inserir um novo nó anterior ao nó encontrado pelo nome. " << endl;
  cout << " 4. Alterar o conteúdo de um nó encontrado pelo peso. " << endl;
  cout << " 5. Consultar o nó anterior ao nó da posição K+1. " << endl;
  cout << " 6. Remover nó da posição K. " << endl;
  cout << " 7. Procurar um nó por ID e remover o nó da posição posterior ao nó encontrado. " << endl;
  cout << " 8. ! Descrição Errada do Almir. ! " << endl;
  cout << " 9. ! Descrição Errada do Almir. ! " << endl;
  cout << " 10. Procurar um nó por ID e alterar o conteúdo do nó posterior encontrado. " << endl;
  cout << " 11. ! Descrição Errada do Almir. ! " << endl;
  cout << " 12. Imprimir o conteúdo da Lista. " << endl;
  cout << " 13. ! Descrição Errada do Almir. ! " << endl;
  cout << " 14. Imprimir os nós da Lista que estão armazenados em índices ímpares. " << endl;
  cout << " 15. Finalizar aplicação. " << endl;

  cout << endl;
  cout << " ";
  cin >> menu;

  switch (menu) {
    case 1: {  //**Inserindo dados na Lista**
      for (int cont = 0; cont < n; cont++){
      sinal = 'F';
      if (final != n-1){
        cout << endl;
        cout << "Informe o valor do animal " << cont + 1 << ": " << endl;
        cout << "ID: ";
        cin >> val.id;

        cin.ignore();

        cout << "Nome: ";
        getline(cin, val.nome);
        cout << "Idade: ";
        cin >> val.idade;
        cout << "Sexo (F/M): ";
        cin >> val.sexo;

        cin.ignore();

        cout<< "Raça: ";
        getline(cin, val.raca);
        cout<< "Peso: ";
        cin >> val.peso;
        cout<< "Confirma a inserção? (S/N): ";
        cin >> conf;

        if (conf == 'S' || conf == 's'){
          final++;
          lst[final] = val;
          sinal = 'V';
          cout << endl << "Inserir mais um animal? (S/N): "; //**Confirmar mais uma inserção** 
          cin >> conf;
          if (conf == 'N' || conf == 'n'){
            break;
          }
        } else {
          cout << "Dados não confirmados." << endl;
        }
      } else {
        cout << "Lista cheia - Overflow" << endl;
      }
    }
      break;
    }

    case 2: { //**Inserir na posição K+1**
      sinal = 'F';
      if (final != n-1){
        cout << endl << "Informe o valor de K a ser inserido os dados no posterior: ";
        cin >> k;
        if (k >= 0 && k <= final){
          cout << "Informe os dados do animal a ser inserido: " << endl;
          cout << "ID: ";
          cin >> val.id;

          cin.ignore();

          cout << "Nome: ";
          getline(cin, val.nome);
          cout << "Idade: ";
          cin >> val.idade;
          cout << "Sexo (F/M): ";
          cin >> val.sexo;

          cin.ignore();

          cout<< "Raça: ";
          getline(cin, val.raca);
          cout<< "Peso: ";
          cin >> val.peso;
          cout<< "Confirma a inserção? (S/N): ";
          cin >> conf;

          if (conf == 'S' || conf == 's'){
            final++;
            aux = final;
            while (aux != k + 1){
              lst[aux] = lst[aux - 1];
              aux -= 1;
            }
            lst[k + 1] = val;
            sinal = 'V';
            cout << endl << "Inserção feita com sucesso." << endl;
          } else {
            cout << "Dados não confirmados." << endl;
          }
        } else {
          cout << "K não pertence a lista." << endl;
        }
      } else {
        cout << "Lista cheia - Overflow" << endl;
      }
    break;
    }

    case 3: { //**Procurar um nó por nome e inserir um novo nó ant. ao encontrado**
      sinal = 'F';
      if (final >= 0 && final < n-1){
        cout << endl << "Informe o nome do cachorro a ser procurado: ";
        cin.ignore();
        getline(cin, srchn);
        aux = 0;
        while (aux != final && lst[aux].nome != srchn){
          aux++;
        }
        if (lst[aux].nome == srchn){
          cout << endl << "Informe os dados do novo cachorro a ser inserido: " << endl;
          cout << "ID: ";
          cin >> val.id;

          cin.ignore();

          cout << "Nome: ";
          getline(cin, val.nome);
          cout << "Idade: ";
          cin >> val.idade;
          cout << "Sexo (F/M): ";
          cin >> val.sexo;

          cin.ignore();

          cout<< "Raça: ";
          getline(cin, val.raca);
          cout<< "Peso: ";
          cin >> val.peso;
          cout<< "Confirma a inserção? (S/N): ";
          cin >> conf;
          if (conf == 'S' || conf == 's'){
            final++;
            k = aux - 1;
            aux = final;
            while (aux != k){
              lst[aux] = lst[aux - 1];
              aux -= 1;
            }
            lst[aux] = val;
            sinal = 'V';
            cout << endl << "Inserção feita com sucesso." << endl;
          } else {
            cout << "Dados não confirmados." << endl;
          }
        } else {
          cout << "Nome não pertence na lista" << endl;
        }
      } else {
        if (final == -1){
          cout << "Lista vazia." << endl;
        } else {
          cout << "Lista cheia - Overflow." << endl;
        }
      }
      break;
    }

    case 4: { //**Procurar um nó por peso e alterar o cont. do nó encontrado**
      sinal = 'F';
      if (final >= 0 && final < n-1){
        cout << endl << "Informe o peso do cachorro a ser procurado e substituído: ";
        cin >> srchp;
        aux = 0;
        while (aux != final && lst[aux].peso != srchp){
          aux++;
        }
        if (lst[aux].peso == srchp){
          cout << endl << "Informe os dados do animal a ser inserido: " << endl;
          cout << "ID: ";
          cin >> val.id;

          cin.ignore();

          cout << "Nome: ";
          getline(cin, val.nome);
          cout << "Idade: ";
          cin >> val.idade;
          cout << "Sexo (F/M): ";
          cin >> val.sexo;

          cin.ignore();

          cout<< "Raça: ";
          getline(cin, val.raca);
          cout<< "Peso: ";
          cin >> val.peso;
          cout<< "Confirma a alteração? (S/N): ";
          cin >> conf;
          if (conf == 'S' || conf == 's'){
            lst[aux] = val;
            sinal = 'V';
            cout << endl << "Alteração feita com sucesso." << endl;
          } else {
            cout << "Dados não confirmados." << endl;
          }
        } else {
          cout << "Peso não pertence na lista." << endl;
        }
      } else {
        if (final == -1){
          cout << "Lista vazia." << endl;
        } else {
          cout << "Lista cheia - Overflow." << endl;
        }
      }
      break;
    }

    case 5: { //**Consultar o nó anterior ao nó da posição K+1**
      sinal = 'F';
      if (final != n-1){
        cout << endl << "Informe o valor de K a ser consultado: ";
        cin >> k;
        if (k >= 0 && k <= final){
          cout << endl << "Dados do nó anterior ao nó K + 1: " << endl;
          cout << "ID: " << lst[k].id << endl;
          cout << "Nome: " << lst[k].nome << endl;
          cout << "Idade: " << lst[k].idade << endl;
          cout << "Sexo: " << lst[k].sexo << endl;
          cout << "Raça: " << lst[k].raca << endl;
          cout << "Peso: " << lst[k].peso << endl;
          sinal = 'V';
          break;
        } else {
          cout << "K não pertence a Lista." << endl;
        }
      } else {
        if (final == -1){
          cout << "Lista vazia." << endl;
        } else {
          cout << "Lista cheia - Overflow." << endl;
        }
      }
      break;
    }

    case 6: { //**Remover a posição K**
      sinal = 'F';
      if (final != -1){
        cout << endl << "Informe o K para ser removido: ";
        cin >> k;
        if (k >= 0 && k <= final){
          val = lst[k];
          cout << endl << "Os dados que serão removidos são: " << endl;
          cout << "ID: " << val.id << endl;
          cout << "Nome: " << val.nome << endl;
          cout << "Idade: " << val.idade << endl;
          cout << "Sexo: " << val.sexo << endl;
          cout << "Raça: " << val.raca << endl;
          cout << "Peso: " << val.peso << endl;
          cout<< "Confirma a remoção? (S/N): ";
          cin >> conf;
          if (conf == 'S' || conf == 's'){
            aux = k;
            while (aux != final){
              lst[aux] = lst[aux + 1];
              aux++;
            }
            final -= 1;
            sinal = 'V';
            cout << endl << "Remoção concluída com sucesso." << endl;
        } else {
            cout << "Remoção não confirmada." << endl;
        }
      } else {
          cout << "K não pertence a Lista." << endl;
        }
      } else {
          cout << "Lista Vazia." << endl;
      }
      break;
    }

    case 7: { //**Procurar um nó por ID e remover o nó na posição posterior ao nó encontrado.**
      sinal = 'F';
      if (final != -1){
        cout << endl << "Informe o ID a ser procurado: ";
        cin >> srchid;
        aux = 0;
        while (aux != final && lst[aux].id != srchid){
          aux++;
        }
        if (lst[aux].id == srchid){
          aux++;
          val = lst[aux];
          cout << endl << "Os dados que serão removidos são: " << endl;
          cout << "ID: " << val.id << endl;
          cout << "Nome: " << val.nome << endl;
          cout << "Idade: " << val.idade << endl;
          cout << "Sexo: " << val.sexo << endl;
          cout << "Raça: " << val.raca << endl;
          cout << "Peso: " << val.peso << endl;
          cout<< "Confirma a remoção? (S/N): ";
          cin >> conf;
          if (conf == 'S' || conf == 's'){
            while (aux != final){
              lst[aux] = lst[aux + 1];
              aux++;
            }
            final -= 1;
            sinal = 'V';
            cout << endl << "Remoção concluída com sucesso." << endl;
        } else {
            cout << "Remoção não confirmada." << endl;
        }
      } else {
          cout << "ID não pertence a Lista." << endl;
        }
      } else {
          cout << "Lista Vazia." << endl;
      }
      break;
    }

    case 8: { //**ALMIR ESCREVEU ERRADO A QUESTÃO :( **
      cout << endl << "Almir zuou nóis." << endl;
      break;
    }

    case 9: { //**ALMIR ESCREVEU ERRADO A QUESTÃO :( **
      cout << endl << "Almir zuou nóis." << endl;
      break;
    }

    case 10: { //**Procurar um nó por ID e alterar o conteúdo do nó posterior encontrado**
      sinal = 'F';
      if (final >= 0 && final < n-1){
        cout << endl << "Informe o ID do cachorro a ser procurado e substituído o seguinte: ";
        cin >> srchid;
        aux = 0;
        while (aux != final && lst[aux].id != srchid){
          aux++;
        }
        if (lst[aux].id == srchid){
          cout << endl << "Informe os dados do animal a ser inserido: " << endl;
          cout << "ID: ";
          cin >> val.id;

          cin.ignore();

          cout << "Nome: ";
          getline(cin, val.nome);
          cout << "Idade: ";
          cin >> val.idade;
          cout << "Sexo (F/M): ";
          cin >> val.sexo;

          cin.ignore();

          cout<< "Raça: ";
          getline(cin, val.raca);
          cout<< "Peso: ";
          cin >> val.peso;
          cout << "Confirma a alteração? (S/N): ";
          cin >> conf;
          if (conf == 'S' || conf == 's'){
            lst[aux + 1] = val;
            sinal = 'V';
            cout << endl << "Alteração feita com sucesso." << endl;
          } else {
            cout << "Dados não confirmados." << endl;
          }
        } else {
          cout << "ID não pertence na lista." << endl;
        }
      } else {
        if (final == -1){
          cout << "Lista vazia." << endl;
        } else {
          cout << "Lista cheia - Overflow." << endl;
        }
      }
      break;
    }

    case 11: { //**ALMIR ESCREVEU ERRADO A QUESTÃO :( **
      cout << endl << "Almir zuou nóis." << endl;
      break;
    }

    case 12: { //**Imprimir o conteúdo da Lista**
      sinal = 'F';
      cout << endl << "<---Impressão da Lista:" << endl;
      if (final != -1){
        for (int i = 0; i <= final; i++){
          cout << endl << "Animal " << i << ": " << endl;
          cout << "ID: " << lst[i].id << endl;
          cout << "Nome: " << lst[i].nome << endl;
          cout << "Idade: " << lst[i].idade << endl;
          cout << "Sexo: " << lst[i].sexo << endl;
          cout << "Raça: " << lst[i].raca << endl;
          cout << "Peso: " << lst[i].peso << endl;
        }
      }
      sinal = 'V';
      break;
    }

    case 13: { //**ALMIR ESCREVEU ERRADO A QUESTÃO :( **
      cout << endl << "Almir zuou nóis." << endl;
      break;
    }

    case 14: { //**Imprimir os nós da lista que estão armazenados em índices ímpares**
      sinal = 'F';
      cout << endl << "<---Impressão da Lista (índices ímpares): " << endl;
      if (final != -1){
        for (int i = 1; i <= final; i = i + 2){
          cout << endl << "Animal " << i << ": " << endl;
          cout << "ID: " << lst[i].id << endl;
          cout << "Nome: " << lst[i].nome << endl;
          cout << "Idade: " << lst[i].idade << endl;
          cout << "Sexo: " << lst[i].sexo << endl;
          cout << "Raça: " << lst[i].raca << endl;
          cout << "Peso: " << lst[i].peso << endl;
        }
      }
      sinal = 'V';
      break;  
    }

    case 15: { //**Finaliza o programa**
      cout << endl << "Programa finalizado.";
      return 0;
    }

    default: {
      cout << endl << "Opção invalida, digite novamente." << endl;
      break;
    }
  }

 } while (menu != 15); //**Loop do menu**

}