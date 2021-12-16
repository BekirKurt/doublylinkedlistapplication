typedef struct node {
    char name[20];
    char surname[20];
    char bolum[20];
    int ogrenci_no;
    int sinif;
    struct node* next;
    struct node* prev;
} node;

node *head, *tail;

node* create_node(const char* name, const char* surname , const char* bolum , int ogrenci_no , int sinif) {
    node* student = (node*) malloc(sizeof(node));

    strcpy(student->name, name);
    strcpy(student->surname, surname);
    strcpy(student->bolum, bolum);
    student->ogrenci_no = ogrenci_no;
    student->sinif = sinif;

    return student;
}
void addnode(const char* name, const char* surname , const char* bolum , int ogrenci_no , int sinif){

    node* student = create_node(name, surname ,bolum, ogrenci_no ,sinif);
    if (head == NULL) { // Eðer liste Boþ ise;
        head = student;
        tail = student;
        head->next = NULL;
        tail->next = NULL;
        head->prev = NULL;
        tail->prev = NULL;
    }
    else {
        node* curr = head;
        // traverse iþlemi
        while (curr != NULL )   {
            curr = curr->next;
        }

        if (curr == head) {
            student->next = head;
            head->prev = student;

            head = student;
            head->prev = NULL;
        }
        else if (curr == NULL) {

            tail->next = student;
            student->prev = tail;

            tail = student;
            tail->next = NULL;
            free(curr);
        }
        else {
            curr->prev->next = student;
            student->prev = curr->prev;

            student->next = curr;
            curr->prev = student;
        }
    }

}
void delete_node(int key) {
    if (head == NULL) { // eger liste bos ise
        printf("List is empty.\n");
    }
    else {
        node* curr = head;
        while (curr != NULL && curr->ogrenci_no != key ) {
            curr = curr->next;
        }

        if (curr == NULL) {
            printf("\"%d\" numarali ogrenci listede bulunmuyor\n", key);
        }
        else if (curr == head && curr == tail) {
            free(curr);

            head = NULL;
            tail = NULL;
        }
        else if (curr == head) {
            head = head->next;
            head->prev = NULL;

            free(curr);
        }
        else if(curr == tail) {
            tail = tail->prev;
            tail->next = NULL;

            free(curr);
        }
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            free(curr);
        }
        printf("Ogrenci basariyla silindi...");
        sleep(2);
    }
}
void search(){

    struct node *arama;
    int numara,i=0,flag;
    arama = head;

    if(arama == NULL){
        printf("\nBos Liste");
    }
    else{

        printf("\nAramak istediginiz ogrencinin numarasini giriniz :");
        scanf("%d",&numara);
        while (arama!=NULL){

            if(arama->ogrenci_no == numara){

                printf("\nOgrenci mevcut. Liste sirasi:%d ",i+1);
                printf("\n\nogrenci Bilgileri :\n\nOgrencinin adi: %-10s Ogrencinin soyadi :%-10s Bolum:%-10s Ogrenci no: %d    Sinif:%d\n", arama->name,arama->surname,arama->bolum, arama->ogrenci_no ,arama->sinif);
                flag=0;
                break;
            }
            else{
                flag=1;
            }
            i++;
            arama = arama -> next;
        }
        if(flag==1){
            printf("\nOgrenci bulunamadi.");
        }
    }
    sleep(2);
}
void destroy_list(){

    if (head == NULL) { // eger liste bos ise
        printf("\nBos liste");
    }
    else {
        node* curr = head;
        while (curr != NULL  ) {
            if (curr == NULL) { //
            printf("\nBos liste");
            free(curr);
            }
            else if (curr == head && curr == tail) {
                free(curr);

                head = NULL;
                tail = NULL;
            }
            else if (curr == head) {
                head = head->next;
                head->prev = NULL;

                free(curr);
            }
            else if (curr == tail) {
                tail = tail->prev;
                tail->next = NULL;

                free(curr);
            }
            else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                free(curr);
            }
            curr = curr->next;
        }
    }
    printf("Liste basariyla yok edildi...");
    sleep(2);
}

void print_list(void) {

    if (head == NULL) { // eger liste bos ise
        printf("Bos liste.\n");
    }
    else {
        node* curr = head;
        while (curr != NULL) {
            printf("Ogrencinin adi: %-10s Ogrencinin soyadi :%-10s Bolumu:%-10s Ogrenci no: %-10d    Sinifi:%-10d\n", curr->name,curr->surname,curr->bolum, curr->ogrenci_no ,curr->sinif);
            curr = curr->next;
        }
    }
}
