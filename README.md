<h1 align="center">Árvore Rubro-Negra</h1>
<h2 border="none"> Intordução </h2>
<p>Árvores do tipo rubro-negra ou vermelho-preto são árvores binárias de busca balanceadas, que, de maneira simplificada, é uma árvore de busca binária que insere e remove de forma inteligente, para assegurar que a árvore permaneça aproximadamente balanceada.</p>
<p>Essa estrutura foi inventada no ano de 1972 por Rudolf Bayer, um professor emérito de informática na Universidade Técnica de Munique, que nomeou a estrutura de “Árvores binárias B simétricas” e posteriormente foi renomeada em um artigo publicado em 1978 escrito por Leonidas J. Guibas e Robert Sedgewick.</p>
<h3 border="none" align="center"> Complexidade de Tempo em Notação big O </h3>
<table align="center">
    <thead>
        <th> Algoritmo </th>
        <th> Caso médio </th>
        <th> Pior médio </th>
    </thead>
    <tbody>
        <tr>
            <td> Espaço </td>
            <td> O(n) </td>
            <td> O(n) </td>
        </tr>
        <tr>
            <td> Busca </td>
            <td> O(log n) </td>
            <td> O(log n) </td>
        </tr>
        <tr>
            <td> Inserção </td>
            <td> O(log n) </td>
            <td> O(log n) </td>
        </tr>
        <tr>
            <td> Remoção </td>
            <td> O(log n) </td>
            <td> O(log n) </td>
        </tr>
    </tbody>
</table>


<h2>Estrutura de dado </h2>

<p>A estrutura usada para cada nó de uma árvore rubro-negra é extremamente semelhante a de uma árvore binária simples, a pricipal diferença se dá no acrécimo de uma variável do tipo bolleana para indicar a cor que um determinado nó representa. Nesse caso foi adotado 'false' para a cor vermelha e 'true' para a cor preta.</p>
<p>Dessa forma a estrutura de um nó possui os seguintes atributos: </p>
<ul>
  <li>Chave</li>
  <li>Cor</li>
  <li>Filho Esquerdo</li>
  <li>Filho Direito</li>
  <li>Pai</li>
</ul>
<p>Caso não exista um pai ou um filho de um nó o atributo do ponteiro correspondente apontará para NULL. Nesse código considera-se que esses valores 'NULL' possuem a cor negra e também são tratados como se fossem ponteiros para as folhas da árvore</p>

~~~C
struct Tree{
    capsule key;
    bool cor; // false = vermelho; true = preto
    Tree *esq;
    Tree *dir;
    Tree *pai;
};
~~~


<h2>Propriedades</h2>

<p> Uma árvore Rubro-Negra é uma árvore de busca binária que satisfaz as seguintes propriedades Rubro-Negra:<p>
<ol>
  <li>Um nó é vermelho ou é preto</li>
  <li>A raiz é preta</li>
  <li>Toda folha (NULL) é preta</li>
  <li> Se um nó é vermelho então ambos os seus filhos são
pretos</li>
  <li>Para cada nó p, todos os caminhos desde p até as
folhas contêm o mesmo número de nós pretos</li>
</ol>
<p>Essas regras asseguram uma propriedade crítica das árvores rubro-negras: que o caminho mais longo da raiz a qualquer folha não seja mais do que duas vezes o caminho mais curto da raiz a qualquer outra folha naquela árvore. O resultado é que a árvore é aproximadamente balanceada. </p>
![Alt text](teste.png "teste")
