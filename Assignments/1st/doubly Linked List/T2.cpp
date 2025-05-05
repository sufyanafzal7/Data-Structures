#include <iostream>
using namespace std;

struct products{
    string  productName;
    products *next;
    products *prev;
};

struct sections{
    string sectionName;
    sections *next;
    sections *prev;
    products *productsFirst;
    products *productsLast;
};

struct  stores{
    string storeName;
    stores *next;
    stores *prev;
    sections *sectionsFirst;
    sections *sectionsLast;
};

stores *storesFirst=NULL;
stores *storesLast=NULL;

void addStore(string Name){
    stores *newStore=new stores;
    newStore->next=NULL;
    newStore->prev=NULL;
    newStore->storeName=Name;
    newStore->sectionsFirst=NULL;
    newStore->sectionsLast=NULL;

    if(storesFirst==NULL){
        storesFirst=storesLast=newStore;
        return;
    }

    newStore->prev=storesLast;
    storesLast->next=newStore;
    storesLast=newStore;
}

stores* searchStore(string Name){
    stores *current=storesFirst;
    while(current!=NULL){
        if(current->storeName==Name){
            return current;
        }
        current=current->next;
    }
    return NULL;
}

void addSection(string sName,string Name){
    stores *currentStore=searchStore(sName);
    if(currentStore==NULL){
        cout<<"Store Not Exist"<<endl;
        return;
    }
    sections *newSection=new sections;
    newSection->next=NULL;
    newSection->prev=NULL;
    newSection->sectionName=Name;
    newSection->productsFirst=NULL;
    newSection->productsLast=NULL;

    if(currentStore->sectionsFirst==NULL){
        currentStore->sectionsFirst=currentStore->sectionsLast=newSection;
        return;
    }

    newSection->prev=currentStore->sectionsLast;
    currentStore->sectionsLast->next=newSection;
    currentStore->sectionsLast=newSection;
}

sections* searchSection(string storeName,string Name){
    stores *currentStore=searchStore(storeName);
    if(currentStore==NULL){
        cout<<"Store Not Exist"<<endl;
        return NULL;
    }
    sections *currentSection=currentStore->sectionsFirst;
    while(currentSection!=NULL){
        if(currentSection->sectionName==Name){
            return currentSection;
        }
        currentSection=currentSection->next;
    }
    return NULL;
}

void addProduct(string storeName,string sectionName,string productName){
    sections* currentSection=searchSection(storeName,sectionName);
    if(currentSection==NULL){
        cout<<"Section not exist"<<endl;
        return;
    }
    products *newProduct=new products;
    newProduct->next=NULL;
    newProduct->prev=NULL;
    newProduct->productName=productName;

    if(currentSection->productsFirst==NULL){
        currentSection->productsFirst=currentSection->productsLast=newProduct;
        return;
    }

    newProduct->prev=currentSection->productsLast;
    currentSection->productsLast->next=newProduct;
    currentSection->productsLast=newProduct;
}

void displaySections(string storeName){
    stores *currentStore=searchStore(storeName);
    if(currentStore==NULL){
        cout<<"Store Not Exist"<<endl;
        return;
    }
    sections *currentSection=currentStore->sectionsFirst;
    cout<<"Sections of store "<<storeName<<":"<<endl;
    while(currentSection!=NULL){
        cout<<currentSection->sectionName<<"\t";
        currentSection=currentSection->next;
    }
    cout<<endl<<endl;
}

void displayProducts(string storeName,string sectionName){
    sections* currentSection=searchSection(storeName,sectionName);
    if(currentSection==NULL){
        cout<<"Section not exist"<<endl;
        return;
    }
    cout<<"Products of store "<<storeName<<" and section "<<sectionName<<":"<<endl;
    products *currentProduct=currentSection->productsFirst;
    while(currentProduct!=NULL){
        cout<<currentProduct->productName<<"\t";
        currentProduct=currentProduct->next;
    }
    cout<<endl<<endl;
}

products* searchProduct(string storeName,string sectionName,string productName){
    sections* currentSection=searchSection(storeName,sectionName);
    if(currentSection==NULL){
        cout<<"Section not exist"<<endl;
        return NULL;
    }
    products *currentProduct=currentSection->productsFirst;
    while(currentProduct!=NULL){
        if(currentProduct->productName==productName){
            return currentProduct;
        }
        currentProduct=currentProduct->next;
    }
    return NULL;
}

void removeProduct(string storeName,string sectionName,string productName){
    products *currentProduct=searchProduct(storeName,sectionName,productName);
    sections *currentSection=searchSection(storeName,sectionName);
    if(currentProduct==NULL){
        cout<<"Product Not exist"<<endl;
        return;
    }
    if(currentProduct->next==NULL){
        currentProduct->prev->next=currentProduct->next;
        currentSection->productsLast=currentProduct->prev;
    }
    else if(currentProduct->prev==NULL){
        currentProduct->next->prev=currentProduct->prev;
        currentSection->productsFirst=currentProduct->next;
    }
    else{
        currentProduct->prev->next=currentProduct->next;
        currentProduct->next->prev=currentProduct->prev;
    }
    delete currentProduct;
}

int main(){
    addStore("Store 1");
    addSection("Store 1","Toys");
    addSection("Store 1","fruits");
    addSection("Store 1","Vegetables");
    addProduct("Store 1","fruits","Apple");
    addProduct("Store 1","fruits","Grapes");
    addProduct("Store 1","fruits","Banana");
    addProduct("Store 1","fruits","Orange");
    addProduct("Store 1","fruits","Mango");
    displaySections("Store 1");
    displayProducts("Store 1","fruits");
    removeProduct("Store 1","fruits","Apple");
    displayProducts("Store 1","fruits");

    addStore("Store 2");
    addSection("Store 2","Books");
    addSection("Store 2","Electronic Products");
    addProduct("Store 2","Books","DSA");
    addProduct("Store 2","Books","OOP");
    addProduct("Store 2","Books","Calculus");
    displaySections("Store 2");
    displayProducts("Store 2","Books");
    removeProduct("Store 2","Books","OOP");
    displayProducts("Store 2","Books");
    return 0;
}