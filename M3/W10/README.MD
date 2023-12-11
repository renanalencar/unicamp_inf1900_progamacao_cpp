
# INF1900 - Recursos Avançados de C++ (2023)
## Exercício 5 - Windows API

### Contexto
Neste trabalho, voce estara mergulhando no mundo do ATL (Active Template Library) e do MFC (Microsoft
Foundation Classes).
O exercıcio  e formado por duas partes, ou seja, dois projetos distintos. Na parte 1, o objetivo principal  ́e
desenvolver uma aplicacao que utiliza a ATL para programar um aproximador de π. Na parte 2 o objetivo  ́e
utilizar o mesmo enunciado do exercıcio 4, mas agora utilizando o MFC.

### Parte 1 - ATL: Desenvolvendo um aproximador de π
Voce sera responsavel por desenvolver uma classe chamada Calculator utilizando ATL. Esta classe sera responsavel por calcular uma aproximacao do numero π.

1. definição da IDL - Calculator.idl: No arquivo Calculator.idl, defina a interface para a sua classe.

Essa interface COM, que pode ser nomeada como ICalculator, deve expor um método chamado ApproximatePi. Este retornar ́a um double representando a aproximação de π. Utilize as diretivas apropriadas

do IDL para garantir que a interface seja registrada corretamente e que possa ser acessada por outros
componentes COM.
2. implementação do Header - Calculator.h: Comece incluindo as diretivas e bibliotecas necessarias
para a operação com ATL. A classe Calculator deve ser derivada de uma classe base adequada do ATL,
como CComObjectRootEx e CComCoClass. Implemente as macros necessarias para registrar a classe
como um componente COM, como DECLARE REGISTRY RESOURCEID(IDR CALCULATOR).
Declare o método ApproximatePi e qualquer outro método necess ́ario para a operação COM.
3. implementação da Classe - Calculator.cpp : No arquivo Calculator.cpp, voce precisar ́a implementar
a l ́ogica para calcular uma aproximação do n ́umero π. Uma maneira comum de fazer isso  ́e utilizando o
método de Monte Carlo, que se baseia em simula ̧c ̃oes aleat ́orias. Para este método:
(a) Imagine um c ́ırculo inscrito em um quadrado. O lado do quadrado tem comprimento 2 e o c ́ırculo
tem raio 1.
(b) Gere pontos aleatorios dentro do quadrado.
(c) Determine a proporção de pontos que caem dentro do c ́ırculo.
(d) Usando essa proporção, voce pode estimar o valor de π como:

π ≈ 4 × numero de pontos dentro do cırculo \ numero total de pontos

4. Cliente - Cliente.cpp: Finalmente, em Cliente.cpp, voce criar ́a um cliente simples para testar sua classe
Calculator

### Parte 2 - MFC: Refazendo o Exercício 4 com a utilizaçao de MFC
Agora, voce irá refazer o exerc ́ıcio feito com a Windows API, mas utilizando o MFC.
1. Comece pela criação da janela principal. Utilize a classe CFrameWndo ou uma derivada dela. Dentro
desta janela, adicione um controle CEdit para que os usu ́arios possam inserir uma string, bem como um
botao usando a classe CButton
2. Aproveite a arquitetura de manipulação de mensagens do MFC, evitando a necessidade de implementar

manualmente a função WndProc. Para estabelecer mapeamentos entre mensagens e funções de manip-
ulação, utilize as macros BEGIN MESSAGE MAP e END MESSAGE MAP.

3. Configure os manipuladores de eventos para os controles. Isso pode ser feito com o aux ́ılio do Class Wizard
ou adicionando manualmente. Associe, por exemplo, o evento de clique do botao a um metodo especıfico,
como OnButtonClicked.
4. Na ação do botao, recupere o texto do controle CEdit e use AfxMessageBox para exibir o conteudo
em uma MessageBox.