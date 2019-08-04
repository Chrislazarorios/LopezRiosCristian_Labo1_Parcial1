int controller_loadFromText(char* path , LinkedList* pArrayListLlamada);
int controller_loadFromBinary(char* path , LinkedList* pArrayListLlamada);
int controller_addLlamada(LinkedList* pArrayListLlamada);
int controller_editLlamada(LinkedList* pArrayListLlamada);
int controller_removeLlamada(LinkedList* pArrayListLlamada);
int controller_ListLlamada(LinkedList* pArrayListLlamada);
int controller_sortLlamada(LinkedList* pArrayListLlamada);
int controller_saveAsText(char* path , LinkedList* pArrayListLlamada);
int controller_saveAsBinary(char* path , LinkedList* pArrayListLlamada);

int controller_filter1(void* this);
int controller_filter2(void* this);
int controller_filter3(void* this);
int controller_filter4(void* this);
int controller_filter5(void* this);
int controller_saveAsText3(char* path , LinkedList* pArrayListLlamada, int tipoProblem);
void allForOne(char* path, LinkedList* listaLlamadas);


int controller_findLlamadaById(LinkedList* pArrayListLlamada, int id);
int controller_comparisonString(void *this,void *that);

//int controller_cantidadDeFotosReveladas(void* this);
//int controller_cantidadDeFotosPrecio300(void* this);
//int controller_cantidadDeFotosPrecio150(void* this);
//int controller_cantidadDeFotosPolaroid(void* this);

