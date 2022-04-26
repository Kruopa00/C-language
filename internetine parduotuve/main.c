#include <stdio.h>
#include <stdlib.h>

int get_user_menu_choice();
void default_text();
void add_product(FILE* f, int added_count);
double get_product_price();
void html_beggining(FILE* f, char website_name[]);
void get_website_name(char* website_name);
int inc_added_count(int added_count);
void html_ending(FILE* f);

struct product{
	char name[255];
	double price;
	char photo_link[500];
};

int main(){

	char* website_name = malloc(30);
	int added_count=0;
	FILE* f = fopen("index.html", "w");
	default_text();
	printf("\n");
    printf("Iveskite internetines parduotuves pavadinima: \n");
    fgets(website_name, 40, stdin);
	html_beggining(f, website_name);	

	while (1){
		int user_choice = get_user_menu_choice();
		switch(user_choice){
			case 0:
				printf("\n");
				printf("Programa baigia darba!\n");
				exit(0);
			case 1:
				add_product(f, added_count);
				break;
			case 3:
				html_ending(f);
				fclose(f);
				break;
		}
	}
	
	return 0;
}

void default_text(){ // funkcija spausdinanti programos aprasyma
    printf("\n");
    printf("Si programa sukuria internete parduotuve, remdamasi vartotojo ivestais duomenimis!\n");
    printf("\n");
    printf("Galimos komandos:\n");
    printf("0 - iseiti is programos\n");
    printf("1 - prideti prekes\n");
    printf("2 - nurodyti internetines parduotuves pavadinima\n");
    printf("3 - sukurti internetines parduotuves file'a (.html)\n");

    printf("\n");
    printf("Pries sukuriant .html file'a, butina nurodyti parduotuves pavadinima, bei prideti bent viena preke!\n");
}

int get_user_menu_choice(){ // funkcija gaunanti simboli is vartotojo
    int input;

    printf("\n");
    printf("Jusu pasirinkimas: ");
    while(1){
        while(scanf("%d", &input) != 2 && getchar() != '\n'){
            while(getchar() != '\n')
                ;
            printf("\n");
            printf("Bloga ivestis!\n");
            printf("Bandykite dar karta: ");
        }
        if (input == 0 || input == 1 || input == 2 || input == 3)
            break;
        printf("\n");
        printf("Bloga ivestis! Tokio pasirinkimo nera.\n");
        printf("Bandykite dar karta: ");
    }

    return input;
}

double get_product_price(){ 
    double input;
	
	while(scanf("%lf", &input) != 2 && getchar() != '\n'){
        while(getchar() != '\n')
            ;
		printf("\n");
	    printf("Bloga ivestis!\n");
		printf("Bandykite dar karta: ");
    }
    
    return input;
}

void add_product(FILE* f, int added_count){
	int products_count;

	printf("\n");
	printf("Iveskite produktu skaiciu: ");
	while(1){ // gauname prekiu skaiciu
		while(scanf("%d", &products_count) != 2 && getchar() != '\n'){
			while (getchar() != '\n')
				;
			printf("Blogai ivestas produktu skaicius!\n");
			printf("Bandykite dar karta: ");
		}
		if (products_count > 30){
			printf("\n");
			printf("Klaida! Siuo metu musu parduotuve palaiko iki 30 produktu.\n");
			printf("Bandykite dar karta: ");
		} else if (products_count <= 0){
			printf("\n");
			printf("Klaida! Produktu skaicius negali buti lygus ar mazesnis uz 0!\n");
			printf("Bandykite dar karta: ");
		}else
			break;
	}

	//printf("%d", products_count);
	
	for (int i=0; i<products_count; i++){
		struct product prod;

		printf("\n");
		printf("Preke Nr.%d", i+1);
		printf("\n");
		printf("\n");
		
		printf("Pavadinimas: ");
		fgets(prod.name, 255, stdin);
		printf("Prekes kaina: ");
		prod.price = get_product_price();
		printf("Paveiksliuko adresas: ");
		fgets(prod.photo_link, 500, stdin);
		printf("\n");
	
		// prekes pridejimas
		if (added_count < 6){ // naujo row kurti nereikia
			fprintf(f, "<div class=\"preke_wrap\">          <div class=\"preke\">            <div class=\"discount\">              %%            </div>            <div class=\"imgwrap\">            <img src=\"%s\" alt=\"\">            </div>            <div class=\"prekes_pav\">              <p>\"%s\"</p>            </div>            <div class=\"parametrai\">              <div class=\"kaina\">                %.2lf €              </div>              <div class=\"mygtukas\">pirkti</div> </div> </div> </div>", prod.photo_link, prod.name, prod.price);
			added_count = inc_added_count(added_count);
		} else if (added_count == 6){ // gale sukuriame nauja row ir uzdarome buvusi
			fprintf(f, "<div class=\"preke_wrap\">          <div class=\"preke\">            <div class=\"discount\">              %%            </div>            <div class=\"imgwrap\">            <img src=\"%s\" alt=\"\">            </div>            <div class=\"prekes_pav\">              <p>\"%s\"</p>            </div>            <div class=\"parametrai\">              <div class=\"kaina\">                %.2lf €              </div>              <div class=\"mygtukas\">pirkti</div> </div> </div> </div> </div> <div class=\"row\">", prod.photo_link, prod.name, prod.price);
			added_count = inc_added_count(added_count);
		}

		//printf("%d", added_count);
	}
}

int inc_added_count(int added_count){
	return ++added_count;
}

void html_beggining(FILE* f, char website_name[]){
	// Kartu su html ir css pradziomis, sukuriame ir pirmaji row.
	fprintf(f, "<!DOCTYPE html><html><style>body{  margin: 0;  background-color: #F2EFE9;}* {  font-family: Arial, Helvetica, sans-serif;}.head{  background-color: #904E55;  height: 75px;  padding: 25px;}h1 {  color: #252627;  margin-left: 40px;}.preke_wrap{  display: inline-block;  width: 15%%;  height: 300px;  margin: 8px;}.preke{  display: inline-block;  margin: auto;  height: 100%%;  width: 100%%;  transition: 0.5s;  border: 1px solid;}.row{  margin: auto;  height: 350px;}main{  min-height: 600px;}.katolgas{  padding: 20px;}.preke:hover{  box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);  cursor: pointer;  transform: scale(1.08);}.imgwrap{  height: 200px;  width: 100%%;  border-bottom: 1px solid;}img{  height: 100%%;  width: 100%%;}.mygtukas{  padding: 5px 15px;  border-radius: 15px;  border: 1px solid;  float: right;  margin: 10px;  margin-right: 20px;}.prekes_pav{  margin: auto;  text-align: center;}.kaina{  float: left;  margin: 10px;  margin-left: 20px;}.discount{  margin: 0;   position: absolute;   padding: 5px;   color: white;   font-size: 18px;   margin-top: 7px;   margin-left: -8px;   border-bottom-right-radius: 15px;   background-color: red;   border: 1px solid black;   box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2); } footer{   background-color: #904E55;   height: 75px;   padding: 25px; } .kontaktai{   padding-top: 50px;   text-align: center;   margin-left: auto;   margin-right: auto; } .kontaktai p{   display: inline-block;   margin: auto; }</style><head>  <title>%s</title></head><body>  <header>    <div class=\"head\"> <h1>%s</h1></div></header><main><div class=\"katolgas\"> <div class=\"row\">", website_name, website_name);
}

void html_ending(FILE* f){
	fprintf(f, "</main>  <footer>    <div class=\"kontaktai\">      <p>tel. nr.</p>      <p>el. pastas</p>    </div>  </footer></body></html>");
}