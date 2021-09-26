// Gabriel Leite de Sousa - 31861571
#include <iostream>
#include <queue>
#include "Node.h"
#include "Tree.h"

int main()
{
    Node* A = new Node();
    Node* B = new Node();
    Node* C = new Node();
    Node* D = new Node();
    Node* E = new Node();
    Node* F = new Node();

    A->SetData("A");
    A->SetLeft(B);
    A->SetRigth(C);
    

    B->SetData("B");
    B->SetParent(A);
    B->SetLeft(D);
    
    C->SetData("C");
    C->SetParent(A);
    C->SetLeft(E);
    C->SetRigth(F);
   
    D->SetData("D");
    D->SetParent(B);
    
    E->SetData("E");
    E->SetParent(C);
    F->SetData("F");
    F->SetParent(C);


    Tree* t = new Tree(A);

    std::cout << "Grau de A:   " << A->GetGrauNode(A) << "\n";
    std::cout << "Nivel de A:  " << t->GetLevel(A, "A") << "\n";
    std::cout << "Altura de A: " << t->GetHeightNode(A, "A") << "\n\n";

    std::cout << "Grau de B:   " << B->GetGrauNode(B) << "\n";
    std::cout << "Nivel de B:  " << t->GetLevel(A, "B") << "\n";
    std::cout << "Altura de B: " << t->GetHeightNode(A, "B") << "\n\n";

    std::cout << "Grau de C:   " << C->GetGrauNode(C) << "\n";
    std::cout << "Nivel de C:  " << t->GetLevel(A, "C") << "\n";
    std::cout << "Altura de C: " << t->GetHeightNode(A, "C") << "\n\n";

    std::cout << "Grau de D:   " << D->GetGrauNode(D) << "\n";
    std::cout << "Nivel de D:  " << t->GetLevel(A, "D") << "\n";
    std::cout << "Altura de D: " << t->GetHeightNode(A, "D") << "\n\n";

    std::cout << "Grau de E:   " << E->GetGrauNode(E) << "\n";
    std::cout << "Nivel de E:  " << t->GetLevel(A, "E") << "\n";
    std::cout << "Altura de E: " << t->GetHeightNode(A, "E") << "\n\n";

    std::cout << "Grau de F:   " << F->GetGrauNode(F) << "\n";
    std::cout << "Nivel de F:  " << t->GetLevel(A, "F") << "\n";
    std::cout << "Altura de F: " << t->GetHeightNode(A, "F") << "\n\n";

    std::cout << "\n\n";
    std::cout << "Esta vazia:          " << (t->TreeVazia() ? "sim" : "nao") << "\n";
    std::cout << "Grau:                " << t->GetGrau() << "\n";
    std::cout << "Altura:              " << t->GetHeight() << "\n";
    std::cout << "Em ordem:            " << t->TransverseInOrder() << "\n";
    std::cout << "Pre Ordem:           " << t->TransversePreOrder() << "\n";
    std::cout << "Pos Ordem:           " << t->TransversePostOrder() << "\n";
    std::cout << "Percorre por nivel:  " ;
    std::cout << "\n";

    t->PrintLevelByLevel(A);


    delete t;
    delete F;
    delete E;
    delete D;
    delete C;
    delete B;
    delete A;
}
