struct gll {
    double lat;
    char latDirection;
    double lon;
    char lonDirection;
    long time;
    char *valid; 
    int offset;
}GLL;

struct gll pfc(char*, struct gll, int);

void comunication (int, double);

double calcolateSpeed(struct gll, struct gll);

double degreesToRadians(double);


