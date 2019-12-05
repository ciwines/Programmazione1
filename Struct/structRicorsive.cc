#include <iostream>
using namespace std;

/*	
 *	è possibile dichiarare una struttura del tipo
 *
 *	struct S {
 *		int val;
 *		S* next; 	(-> lecita poichè ogni puntatore occupa sempre lo stesso spazio in memoria)
 *	}
 *	
 *	ATTENZIONE: non è lecito dichiare questo tipo di struct
 *	struct S {
 *		int val;
 *		S next;		(-> manca il puntatore, in questo caso verrebbe allocata una quantità di memoria infinita)
 *	}
 *
 *	
 *
 *
 */

struct S2;

struct S1{
	int val;
	S2* ptr;
};

struct S2 {
	int val:
	S1* ptr;
};

int main() {

	return 0;
}