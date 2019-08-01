int controller_loadFromText(char* path , LinkedList* pArrayListenvio);
int controller_loadFromBinary(char* path , LinkedList* pArrayListenvio);
int controller_addenvio(LinkedList* pArrayListenvio);
int controller_editenvio(LinkedList* pArrayListenvio);
int controller_removeenvio(LinkedList* pArrayListenvio);
int controller_Listenvio(LinkedList* pArrayListenvio);
int controller_sortenvio(LinkedList* pArrayListenvio);
int controller_saveAsText(char* path , LinkedList* pArrayListenvio);
int controller_saveAsBinary(char* path , LinkedList* pArrayListenvio);

int controller_map0(void* this);
int controller_map1(void* this);
int controller_map2(void* this);
int controller_map3(void* this);
int controller_map4(void* this);
int controller_map5(void* this);
int controller_saveAsText3(char* path , LinkedList* pArrayListenvio, int tipoProblem);
void allForOne(char* path, LinkedList* listaenvios);


int controller_findenvioById(LinkedList* pArrayListenvio, int id);
int controller_comparisonString(void *this,void *that);

//int controller_cantidadDeFotosReveladas(void* this);
//int controller_cantidadDeFotosPrecio300(void* this);
//int controller_cantidadDeFotosPrecio150(void* this);
//int controller_cantidadDeFotosPolaroid(void* this);

