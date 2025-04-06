using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        // **Criação da lista**
        List<string> nomes = new List<string>();

        // **Adição de elementos**
        nomes.Add("Alice");
        nomes.Add("Bob");
        nomes.Add("Charlie");

        // **Acesso a elementos**
        Console.WriteLine("Primeiro nome: " + nomes[0]); // Alice
        Console.WriteLine("Segundo nome: " + nomes[1]);  // Bob

        // **Remoção de elementos**
        nomes.Remove("Bob");  // Remove pelo valor
        nomes.RemoveAt(0);    // Remove pelo índice (remove Alice)

        // **Iteração sobre a lista**
        Console.WriteLine("Nomes restantes:");
        foreach (string nome in nomes)
        {
            Console.WriteLine(nome); // Exibe os nomes restantes
        }

        // **Métodos úteis**
        // Verifica se a lista contém um elemento específico
        bool contemCharlie = nomes.Contains("Charlie");
        Console.WriteLine("A lista contém Charlie? " + contemCharlie);

        // Encontra o índice de um elemento
        int indiceDeCharlie = nomes.IndexOf("Charlie");
        Console.WriteLine("Índice de Charlie: " + indiceDeCharlie);

        // Ordena a lista
        nomes.Sort();
        Console.WriteLine("Lista ordenada:");
        foreach (string nome in nomes)
        {
            Console.WriteLine(nome);
        }
    }
}