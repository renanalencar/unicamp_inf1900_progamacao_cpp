# Atividade Prática 1: Herança, Sobrecarga, Sobrescrita e Alocação de Objetos

Desenvolva o mini-game em C++ chamado Jewel Collector v1.0. O objetivo deste jogo é que um robô, controlado pelo teclado, se desloque por um mapa 2D procurando comida e coletando as joias presentes no ambiente. Entretanto, neste momento, iremos nos concentrar apenas no desenvolvimento do ambiente de jogo. Para isso, as seguintes classes devem ser criadas:

1. Item: A classe Item é responsável por representar os elementos presentes no mapa do jogo. Cada item é caracterizado por dois atributos: o tipo, que é a identificação do item (por exemplo, joia, comida); e o valor, que é um número para indicar a relevância desse item no contexto do jogo. Lembre-se de criar os métodos getters e setters para os atributos da classe, se julgar necessário. Em seguida, crie as classes Jewel e Food que herdam as propriedades da classe Item.
2. Treasure: Implemente a classe Treasure que poderá conter várias joias e comidas dinamicamente. Use vector para criar coleções destes elementos dentro da classe. Implemente métodos para adicionar e remover comida e joias do baú. Como o baú possui muitos itens, você precisará sobrescrever o método getValue() para retornar o valor total do baú como sendo a soma dos valores individuais de cada item. Você também precisará usar sobrecarga de métodos para implementar o método de adição de elementos no baú. Para isso, crie o método add() usando sobrecarga para permitir a adição de itens que sejam comida e joias no baú.
3. Map: A classe Map deverá armazenar as informações do mapa 2D e implementar métodos para adição e remoção de itens no ambiente. Além de um método para imprimir o mapa na tela. A impressão do mapa deverá seguir a seguinte regra: Jewel como J, Treasure como T; Espaços vazios como ' '.
Crie um mapa com dimensões 10x10, insira algumas joias e um baú no ambiente. A quantidade de joias individuais e a posição de todos os elementos do mapa são definidas a seu critério. Ao exibir o mapa na tela certifique-se de imprimir a quantidade de joias e de comida que existe no baú, assim como os valores totais desses elementos. Teste se as funções de adicionar/remover itens do mapa e do baú estão funcionando corretamente. O programa é encerrado apenas quando o usuário digita "exit" no prompt, caso contrário, o usuário pode optar por modificar o mapa ou exibí-lo na tela.

## Referencias
- [How to properly add include directories with CMake](https://stackoverflow.com/questions/13703647/how-to-properly-add-include-directories-with-cmake)

## Autores
- [@rottaveira](https://www.github.com/rottaveira)
- [@renanalencar](https://www.github.com/renanalencar)


## Deploy

Para fazer o deploy desse projeto rode

```bash
  cmake -S . -B Build -G "MinGW Makefiles"
  cmake --build INF1900_M2_lab1\
  make jewel_collector
```
