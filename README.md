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

'''C
struct Tree{
    capsule dado;
    bool cor; // false = vermelho; true = preto
    Tree *esq;
    Tree *dir;
    Tree *pai;
};
'''
