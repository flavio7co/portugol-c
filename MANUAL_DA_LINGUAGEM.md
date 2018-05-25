# Manual da linguagem Portugol-C

## A Linguagem Estruturada

Utilizaremos uma adaptação da linguagem estruturada para se assemelhar mais com a linguagem linguagem C. Um algoritmo é executado sequencialmente, a partir do topo até a parte inferior do código. No exemplo abaixo podemos ver o Algoritmo DobroSete:

```
Algoritmo DobroSete
inicio
	 inteiro x;
	 x <- 7*2;
	 escreva("O dobro de sete é: ");
	 escreva(x);
fim
```

O algoritmo acima não é muito útil, afinal todos sabemos que o dobro de sete é quatorze. Mas ele serve perfeitamente para ilustrar a estrutura de um pseudocódigo de programação. Vamos a algumas regras:

- Com exceção da palavra __Algoritmo__ (pode-se também escrever __algoritmo__) todos os comandos e palavras reservadas serão padronizados em minúsculo. 
- Tudo que aparecer entre as palavras reservadas inicio e fim deverá ser tabulado. A isto chamamos de identação de código e serve para tornar o código mais legível.
- Deve-se inserir um __;__ (ponto e vírgula) ao final de cada linha entre o inicio e o fim do algoritmo. Algumas excessões serão citadas mais à frente.
- Recomenda-se que as declarações de variáveis aconteçam sempre nas primeiras linhas do código, garantindo assim que elas estejam devidamente declaradas quando da sua utilização.
- Só será permitido utilizar em um algoritmo 6 ítens: 
	- palavras reservadas, 
	- identificadores (nomes de variáveis e do programa), 
	- constantes (números), 
	- expressões literais (frases) entre aspas, 
	- operadores (apenas os que forem definidos, por hora <-, +, -, *, / e %) e 
	- pontuação. Ex: ; , ) " (  

### Palavras reservadas

Palavras reservadas são aquelas que não podem ser utilizadas como identificadores (nome do algoritmo ou variáveis) pois elas possuem alguma função dentro da linguagem de programação. 

No nosso caso, além das palavras __Algoritmo__, __inicio__, __fim__ já explicadas anteriormente usaremos as palavras reservadas __escreva__, __leia__ e __novalinha__ que representam comandos de entrada e saídas no nosso pseudocódigo. Todas as 3 palavras reservadas acompanhadas de (), onde serão inseridos os parâmetros.

A palavra __escreva__ é equivalente ao símbolo ![](png/saida.png) do fluxograma. Lembrando que assim como no fluxograma iremos inserir como parâmetro a variável ou frase (entre "") que desejamos exibir. Para isto inserimos o que desejamos exibir entre parênteses. Desta forma se desejo exibir o conteúdo da variável x devo utilizar o comando desta forma: ```escreva(x);``` Se desejar escrever Olá mundo! na tela devo utilizar o comando assim: ```escreva("Olá mundo!");``` 

A palavra reservada __leia__ é equivalente ao símbolo ![](png/entrada.png) do fluxograma. Dentro deste símbolo é inserido o nome da variável em que desejamos inserir o valor digitado. Assim se eu desejar ler um valor e colocá-lo na variável y devo utilizar o comando assim: ```leia(y);```

Não existe equivalente em fluxograma da palavra reservada __novalinha__. Ela é utilizada quando desejamos propositalmente exibir uma quebra de linha na tela (por exemplo exibir duas frases em linhas diferentes). Para utiliza-la devemos colocar entre parênteses o número de linhas que desejamos pular. Ex: ```novalinha(1);``` (insere uma quebra de linha). 

Abaixo vemos o algoritmo DobroDeUmNumero que exemplifica a utilização das palavras reservadas leia, escreva e novalinha.

```
Algoritmo DobroDeUmNumero
inicio
		inteiro x, y;
		escreva("Por favor, digite um número inteiro: ");
		leia(x);
		y <- x*2;
		escreva("Você digitou o número: ");
		escreva(x);
		novalinha(1);
		escreva("O dobro deste número é: ");
		escreva(y);
fim
```
 
Este algoritmo já é um pouco mais útil do que mostrar o dobro de sete pois ele exibe o dobro de qualquer número que o usuário digitar. 

A leitura é realizada pela palavra leia e o valor lido é inserido na variável x. O comando novalinha foi utilizado para inserir uma linha entre a exibição das mensagens de resposta após a operação que calcula o dobro ser realizada.

As palavras que identificam os tipos de variáveis também são palavras reservadas. Elas serão apresentadas a seguir.

### Tipos de variáveis

As variáveis nada mais são do que uma posição de memória, reservada pelo sistema operacional e apelidada com o nome que você escolheu seguindo o padrão tipo<espaço>nome (Ex: inteiro numero). 

Inicialmente utilizaremos três tipos de variáveis: __inteiro__, __real__ e __literal__.

__inteiro__: representa números não fracionários. Utiliza-se em situações cujas unidades são indivisíveis. Ex: Se você tem 3 carros e deve dividi-los para duas pessoas, não se pode dar um carro e meio para cada uma pois dividir um carro o faria parar de funcionar. Neste caso cada pessoa fica com um carro e sobra um carro (talvez seja melhor vendê-lo e dividir o dinheiro – este sim é divisível).

__real__: representa números fracionários. Utiliza-se em situações em que pode-se dividir a unidade. Ex: se você deseja dividir 3 bolos para 2 pessoas. Neste caso podemos ter um bolo e meio para cada uma. 

__literal__: representa o armazenamento de um caracter (símbolos, letras, etc). Ex: caso você queira armazenar a resposta de uma questão da prova em que uma pessoa pode escolher entre a, b, c ou d.

Os tipos são necessários para permitir que o programa saiba a quantidade de memória a ser reservada. Também interfere na lógica do sistema quando por exemplo calcula que a divisão de 3 por 2 é 1 (e sobra 1) quando a variável é inteira. Por fim, permite a exibição adequada do que foi lido (se a variável é real deve-se exibir as casas decimais, se for inteiro não. Se a variável for do tipo literal deve-se exibir um valor literal, não um valor numérico).

### Identificadores

Identificadores são os nomes que escolhemos para a declaração de variáveis e para nomear o algoritmo. Estes nomes servem para diferenciar as variáveis das demais e para identificá-las no código e devem seguir o seguinte padrão:

- Só poderemos utilizar no identificador números, letras ou _;
- Como consequência disto não pode-se utilizar nenhum caracter especial (diferente de _) como acentos, virgulas, espaços, etc;
- O identificador deve sempre começar com uma letra;
- Não pode-se ter dois identificadores com mesmo nome;
- Não se pode utilizar como identificador uma palavra reservada.

### Operadores

Inicialmente utilizaremos apenas os operadores: + soma; - subtração; * multiplicação; / divisão; <- atribuição.

Na atribuição <- a variável que está à esquerda recebe o valor ou resultado da operação que está à direita. Ex: x <- 3+4; Neste caso x irá receber 7.

Podemos incluir o operador % (módulo) que é utilizado para pegar o valor da divisão entre dois números inteiros. Não confunda este operador com percentual que é um operador não utilizado em Portugol-C.  Ex: Na expressão 11%3 o resultado será 2. 

Entretanto, na expressão anterior este valor não foi armazenado. Se desejar utilizar o resultado em outra parte do algoritmo seria interessante atribui-lo a alguma variável (ex: z <- 11%3;).

### Estrutura de decisão (se)

Esta estrutura possibilita a escolha entre blocos de comandos diferentes caso a expressão lógica seja verdadeira ou falsa. Em ambos os casos os comandos devem ser inseridos entre as palavras reservadas inicio e fim (lembre-se de identar o código). Não há __;__ após a condição. De fato não há __;__ quando a palavra inicio aparece na outra linha (isto porque o comando não terminou em uma única linha).

A condição é uma expressão lógica e ela utiliza os operadores: <  (menor), > (maior), <= (menor ou igual),>= (maior ou igual), == (igual) e != (diferente).

Também é possível utilizar os conectores lógicos: __&&__ (conector lógico e) e __||__ (conector lógico ou).

Estrutura:

```
se(<condição>)
inicio
  <lista de instruções>
fim senao
    inicio
      <conjunto de instruções>
    fim
```

Exemplo:

```
se(x>=0)
inicio
  escreva("X é positivo ou zero");
fim senao
    inicio
      escreva("X é negativo");
    fim
```

### Estrutura de seleção (escolha)

Esta estrutura possibilita a seleção de comandos inseridos de acordo com a opção desejada. Não se utiliza expressão lógica neste caso, o valor será 'chaveado' como se fosse um botão de um liquidificador para o valor da variável naquele ponto do código.

A opção __padrao__ é acionada quando o valor está fora da faixa determinada dentro dos casos disponíveis. 

A palavra __abandone__ deve ser utilizada pois caso ela seja omitida, assim que a opção for acionada ela executará todas abaixo dela.

Estrutura:

```
escolha(<variável>)
inicio
  caso 1: <lista de instruções>
          abandone:
  caso 2: <lista de instruções>
          abandone:
  caso n: <lista de instruções>
          abandone:
  padrao: <lista de instruções>
fim
```

Exemplo:

```
escolha(dia)
inicio
  caso 1: escreva("Domingo");
          abandone:
  caso 2: escreva("Segunda");
          abandone:
  caso 3: escreva("Terça");
          abandone:
  caso 4: escreva("Quarta");
          abandone:
  caso 5: escreva("Quinta");
          abandone:
  caso 6: escreva("Sexta");
          abandone:
  caso 7: escreva("Sábado");
          abandone:
  padrao: escreva("Este não é um valor válido para dia da semana");
fim
```


### Estrutura de repetição (enquanto)

Esta estrutura possibilita a repetição de comandos inseridos entre seu inicio e fim (lembre-se de identar o código). Não há __;__ após a condição. De fato não há __;__ quando a palavra inicio aparece na outra linha (isto porque o comando não terminou em uma única linha).

A condição é uma expressão lógica e ela utiliza os operadores: <  (menor), > (maior), <= (menor ou igual),>= (maior ou igual), == (igual) e != (diferente).

Também é possível utilizar os conectores lógicos: __&&__ (conector lógico e) e __||__ (conector lógico ou).

Estrutura:

```
enquanto(<condição>)
inicio
  <lista de instruções>
fim
```

Exemplo:

```
enquanto(x<10)
inicio
  x<-x+1;
  escreva(x);
  novalinha(1);
fim
```
### Códigos C

Como o código em Portugol-C é traduzido para linguagem C, é possível a utilização de comandos ou código em linguagem C (como por exemplo x++, x+=3, etc). Entretanto isto deve ser feito com parcimônia. Caso o usuário deseje utilizar C basta abandonar o Portugol-C e partir para a própria linguagem C.
