
# INF1900 - Recursos Avançados de C++ (2023)

## Exercício 2 - Tratamento de Exceções

### Contexto:
Imagine que você está desenvolvendo uma aplicação que precisa analisar documentos de texto em diferentes idiomas para determinar o idioma predominante em cada documento. Essa análise é fundamental para garantir que os documentos sejam traduzidos corretamente. O primeiro passo é criar um programa que seja capaz de identificar e processar arquivos de texto, considerando a possibilidade de erros e exceções ao longo do caminho.

### Enunciado:
Você deve desenvolver um programa em C++ que leia o nome de um arquivo de texto e execute uma série de operações, fazendo uso da biblioteca `filesystem` para a manipulação de arquivos, e garantindo o tratamento de exceções conforme especificado a seguir:

1. O programa deve solicitar ao usuário o nome de um arquivo de texto e usar a biblioteca `filesystem` para verificar se o arquivo existe.
2. Se o arquivo não existir, o programa deve lançar uma exceção do tipo `std::filesystem::filesystem_error` com uma mensagem apropriada informando que o arquivo não foi encontrado.
3. Se o arquivo existir, o programa deve verificar se o arquivo é um arquivo de texto válido. Para isso, ele deve tentar abrir o arquivo utilizando `std::ifstream` da biblioteca `fstream` e verificar se a abertura foi bem-sucedida.
4. O programa deve tratar as seguintes exceções que podem ocorrer durante a abertura do arquivo com `std::ifstream`:
   - `std::ios_base::failure`: Lançada quando ocorre uma falha na operação de I/O.
   - `std::ifstream::failure`: Uma exceção específica para operações de leitura que falham.
   - `std::bad_alloc`: Lançada quando não há memória disponível para a operação.
   - `std::exception`: Trate outras exceções genéricas de std::exception que possam ocorrer.
5. Você também deve criar sua própria classe derivada de `std::exception` para representar a exceção de arquivo não-texto e lançá-la quando apropriado.
6. Se o arquivo for aberto com sucesso, o programa deve usar `std::getline` ou outras funções de leitura de arquivo para contar o número de linhas, palavras e caracteres.
7. O programa deve exibir essas informações na tela.

Para resolver esse exercício, você deve utilizar as classes e funções da biblioteca `filesystem` para garantir a verificação da existência do arquivo e sua classe de texto. Além disso, deve utilizar blocos try-catch para tratar as exceções de `fstream` mencionadas e outras exceções genéricas.