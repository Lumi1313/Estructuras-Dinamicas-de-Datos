#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;								//data del nodo
    struct Node *next;							//puntero que apunta al siguiente nodo en la lista	
};

int Length(struct Node *head)						//funcion para calcular la longitud de la lista
{
    struct Node *t;
    int i = 0;
    if (head == NULL)								//en caso de que la lista este vacia
    {
        return 0;
    }

    t = head -> next;

    do											
    {												//iterar
        t = t -> next;
        i++;
    } while (t != head->next);
    return i;
}

struct Node *Start(struct Node *head, int data)				//funcion para insertar nodos al principio de la lista
{
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    if (head == NULL)										//en caso de que la lista este vacia
        {
    temp -> data = data;
    head = temp;
    head -> next = head;
        }
    else
    {
    temp -> data = data;
    temp -> next = head -> next;
    head -> next = temp;
    head = temp;
    }
    return head;
}

struct Node *End(struct Node *head, int data)						//funcion para insertar nodos al final de la lista
{
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node)), *a = head;
    if (head == NULL)										//en caso de que la lista este vacia
        {
    temp -> data = data;
    head = temp;
    head -> next = head;
        }
    else
    {
    do
    {
        a = a -> next;
    } while (a -> next != head);							//iterar 
    temp -> data = data;
    temp -> next = a -> next;
    a -> next = temp;
    }
    return head;
}

struct Node *Middle(struct Node *head, int data, int index)				//funcion para insertar nodos en cualquier lugar entre el principio y el final
{
    if (head == NULL)								//en caso de que este vacia (underflow)
    {
        cout << "La lista esta vacia" << endl;
        return NULL;
    }

    int len = Length(head);						//get la longitud de la lista
    if (index > len || index < 0)						//index incorrecto
    {
        cout << "No es posible insertar, error en el input" << endl;
        return head;
    }
    if (index == 0)								//insertar al principio
    {
        head = Start(head,data);
        return head;
    }
    if (index == len)								//insertar al final
    {
        head = End(head,data);
        return head;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)), *a = head;
    do											
    {													//manejar iteraciones de principio a fin
        a = a -> next;
    } while (a -> next != head);
    len = 0;
    while (1)
    {
        if (len == index)							//if para manejar las iteraciones
        {
            temp -> data = data;
            temp -> next = a -> next;
            a -> next = temp;
            return head;
        }
        a = a -> next;
        len++;
    }
}

struct Node *First(struct Node* head)									//borrar un nodo del principio
{
    struct Node *prev = head, *first = head;

    if (head == NULL) {								//underflow
        cout << "La lista esta vacia" << endl;
        return NULL;
    }

    if (prev->next == prev)									//manejar el borrar un solo nodo de la lista
    {
        head = NULL;
        return head;
    }

    while (prev->next != head)
    {
        prev = prev->next;
    }

    prev->next = first->next;

    head = prev->next;
    free(first);
    return head;
}

struct Node *Last(struct Node* head)								//funcion para borrar un nodo al final de la lista
{
    struct Node *curr = head, *temp = head, *prev;

    if (head == NULL) {										//underflow
        cout << "La lista esta vacia" << endl;
        return NULL;
    }

    if (curr->next == curr)									//manejar eliminacion de un solo nodo al final de la lista
    {
        head = NULL;
        return head;
    }

    while (curr->next != head)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    head = prev->next;
    free(curr);
    return head;
}

struct Node *Position(struct Node* head, int index)					//funcion para borrar data en cualquier lugar entre el principio y el final de la lista 
{
    int len = Length(head);
    int count = 1;
    struct Node *prev = head, *next = head;

    if (head == NULL) {										//underflow 
        cout << "La lista esta vacia" << endl;
        return NULL;
    }

    if (index > len || index < 0)								//data invalida 
    {
        cout << "Borrar es imposible, error en la data" << endl;
        return head;
    }

    if (index == 0)
    {
        First(head);
        return head;
    }

    if (index == len)
    {
        Last(head);
        return head;
    }

    while (len > 0)
    {													//navegar y borrar 1
        if (index == count)
        {
            prev->next = next->next;
            free(next);
            return head;
        }
        prev = prev->next;
        next = prev->next;
        len--;
        count++;
    }

    return head;
}

void Display(struct Node *head)										//funcion para navegar la lista
{
    struct Node *t;
    if (head == NULL)
    {
        cout << "La lista enlazada esta vacia." << endl;
        return;
    }

    t = head;

    do
    {
        cout << t -> data << " -> ";
        t = t -> next;
    } while (t != head);
    cout<<" "<<endl;
}

int main()
{
    struct Node *head = NULL;
    int n = 0,a = 0;
    char ch;
    while (1)
    {
    cout << " 1. Añadir al principio\n 2. Añadir al final \n 3. Añadir data \n 4. Mostrar lista \n 5. Quitar del principio \n 6. Quitar del final \n 7. Quitar data \n 8. Salir" << endl;
    cin >> ch;
    switch (ch)
    {
        case '1' :  cout << "Ingresar data" << endl;
                    cin >> n;
                    head = Start(head, n);
                    break;
        case '2' :  cout << "Ingresar data" << endl;
                    cin >> n;
                    head = End(head, n);
                    break;
        case '3' :  cout << "Ingresar data" << endl;
                    cin >> n;
                    cout << "Index en el cual ingresar data" << endl; //ubicacion=index
                    cin >> a;
                    head = Middle(head, n, a);
                    break;
        case '4' :  Display(head);
                    break;
        case '5' :  head = First(head);
                    break;
        case '6' :  head = Last(head);
                    break;
        case '7' :  cout << "Index en el cual ingresar data" << endl;
                    cin >> a;
                    head = Position(head,a);
                    break;
        case '8' : exit(0);
        default : cout << "Error" << endl;
    }
    }
    return 0;
}
