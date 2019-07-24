int controller_loadFromText(char* path , LinkedList* pArrayListVenta);
int controller_loadFromBinary(char* path , LinkedList* pArrayListVenta);
int controller_addVenta(LinkedList* pArrayListVenta);
int controller_editVenta(LinkedList* pArrayListVenta);
int controller_removeVenta(LinkedList* pArrayListVenta);
int controller_ListVenta(LinkedList* pArrayListVenta);
int controller_sortVenta(LinkedList* pArrayListVenta);
int controller_saveAsText(char* path , LinkedList* pArrayListVenta);
int controller_saveAsBinary(char* path , LinkedList* pArrayListVenta);

int controller_findVentaById(LinkedList* pArrayListVenta, int id);
int controller_comparisonString(void *this,void *that);

int controller_cantidadDeFotosReveladas(void* this);
int controller_cantidadDeFotosPrecio300(void* this);
int controller_cantidadDeFotosPrecio150(void* this);
int controller_cantidadDeFotosPolaroid(void* this);

