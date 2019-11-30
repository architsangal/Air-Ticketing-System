
struct data
    {
        char flight_num[100] ;
        char flight_name[100] ;
        char start[100] ;
        char end[100] ;
        char departure[6]  ;    
        char landing[6] ;      
        char travel_time[6] ;  
        char seats[6] ;        
        char price[6] ;

    }   data_set[100] ;        

void get_data(struct data *, char *);

void print_data(struct data * );

void fprint_sort(int );

void sorting1(struct data* , char*);

void sorting2(struct data * , char* );

void sorting3(struct data * , char * );

void sorting4(struct data* , char * );

void sorting5(struct data * , char * );

char * final_sort(struct data *);

void print_sort();

void print_data1();

struct data flight();
























