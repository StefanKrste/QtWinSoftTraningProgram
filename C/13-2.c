#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//zad1
struct stackNode {
    char data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push( StackNodePtr *topPtr, char info );
void printStack( StackNodePtr currentPtr );

//zad3 -
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// zad3 - Функција за креирање ново јазол
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// zad3 - Функција за наоѓање најмала вредност во бинарно пребарувачко дрво
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// zad3 - Функција за бришење на јазол од бинарно пребарувачко дрво
struct TreeNode* deleteNode(struct TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    else if (val < root->val) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    }
    else {
        // Случај 1: Нема деца или само едно дете
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Случај 2: Два деца
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    
    return root;
}

// zad3 - Функција за вметнување на јазол во бинарно пребарувачко дрво
struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }else if (val < root->val) {
        root->left = insertNode(root->left, val);
    }else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }else {
        printf("%d veke postoi vo drvoto.\n", val);
    }
    // Не вметнувај дупликатни вредности
    return root;
}

// zad3 - Функција за извршување на in-order обилажување на бинарното пребарувачко дрво
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->val);
        inOrderTraversal(root->right);
    }
}

int main(){

    //1. Напиши програм кој внесува линија текст и користи стек за да се испечати текстот во обратен дерослед. Текстот да содржи и празни места.

//    StackNodePtr stackPtr = NULL;
//    char value[100];
//
//    printf( "Vnesi go tekstot: " );
//    fgets(value, sizeof(value), stdin);
//    for (int i = 0; i < strlen(value) ; i++) {
//        push( &stackPtr, value[i] );
//    }
//    printStack( stackPtr );

    //2. Модифицирај го програмот р13_04.с за да можеш да внесеш дупли вредности.

        // vo toa dali e dozboleno da se vnesat samo razlicni vrednosti i da ovozmozime dupli vrednoste e vo funkcijata insertNode
        // if ( value < ( *treePtr )->data ) /* podatokot shto se vnesuva e pomal od podatokot vo tekovniot jazel */ (dozvoleno samo razlicni vredmnosti)
        // if ( value <= ( *treePtr )->data ) /* podatokot shto se vnesuva e pomal ili ednakov od podatokot vo tekovniot jazel */ (dozvoleno i dupli vredmnosti)
        // istoto moze da se postigne i so proverkata za desnata strana namesto levata

    //3. Напиши програм кој врши бришење од дрво, така да структурата на дрвото не се губи. Секоја од користените функции да се објасни. (помош: користете web решенија за binary tree delete)

//    struct TreeNode* root = NULL;
//    int choice = 0, val = 0;
//    while (choice != 4) {
//        printf("1. Dodadete nova vrednost vo drvoto\n");
//        printf("2. Izbrisete vrednost vo drvoto\n");
//        printf("3. Prikazi go drvoto\n");
//        printf("4. Izlez\n");
//        scanf("%d", &choice);
//
//        switch (choice) {
//            case 1:
//                printf("Vnesete vrednost za dodavanje vo drvoto: ");
//                scanf("%d", &val);
//                root = insertNode(root, val);
//                break;
//            case 2:
//                printf("Vrednost za brisenje: ");
//                scanf("%d", &val);
//                root = deleteNode(root, val);
//                break;
//            case 3:
//                printf("Vrednostite vo drvoto se: ");
//                inOrderTraversal(root);
//                printf("\n");
//                break;
//            case 4:
//                printf("Izlez.\n");
//                break;
//            default:
//                printf("Nevalidna opcija.\n");
//                break;
//        }
//    }

    return 0;
}

//zad1
void push( StackNodePtr *topPtr, char info ){
    StackNodePtr newPtr;

    newPtr = malloc( sizeof( StackNode ) );

    if ( newPtr != NULL ) {
        newPtr->data = info;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }else {
        printf( "\nNema dovolno memorija.\n");
    }
}

//zad1
void printStack( StackNodePtr currentPtr ){
    if ( currentPtr == NULL ) {
        printf( "\nStekot e prazen.\n" );
    }else {
        printf( "\nTekstot vo obraten redosled e:" );
        while ( currentPtr != NULL ) {
            if(currentPtr != NULL)
            printf( "%c", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
        }
    }
}
