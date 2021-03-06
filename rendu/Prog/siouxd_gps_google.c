#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 *****************************************************************************
 *                          siouxd_gps_google
 *****************************************************************************
 * Ce programme genere aleatoirement une position GPS
 * et l'enregistre dans le fichier position.html
 * MODE D'AFFICHAGE : CARTE GOOGLE
 */
int main()
{
     srand(time(NULL));

    /// 1) calcul de latitude aleatoire

    /// --- generation d'un nombre entre 0 et 80 (90 = pole)
    float latitude = rand() % 80 + (float)rand() / (float)RAND_MAX;

    /// --- generation d'un signe (1 ou -1)
    int signe = rand() % 2 == 0 ? -1 : 1;

    /// --- application du signe sur le nombre (-80 <-> 80)
    latitude *= signe;


    /// 2) calcul de longitude aleatoire

    /// --- generation d'un nombre entre 0 et 180
    float longitude = rand() % 180 + (float)rand() / (float)RAND_MAX;

    /// --- generation d'un signe (1 ou -1)
    signe = rand() % 2 == 0 ? -1 : 1;

    /// --- application du signe sur le nombre (-180 <-> 180)
    longitude *= signe;


    /// 3) ecriture de la position GPS dans le fichier
    char html[1024];

    sprintf(html, "\
<html>\
            <head>\
                <title>GPS</title>\
            </head>\
            <body style=\"text-align: center;\">\
                <br /><br />\
                <p style=\"text-align: center;\">\
                    <h1>Latitude : <b>%f</b></h1>\
                    <h1>Longitude : <b>%f</b></h1>\
                </p>\
                <p>\
                    <img border=\"0\" alt=\"\" src=\"http://maps.googleapis.com/maps/api/staticmap?size=640x480&zoom=4&markers=%f,%f&sensor=false\"/>\
                </p>\
            </body>\
</html>", latitude, longitude, latitude, longitude);

    FILE* fichier_html = fopen("position.html", "w");

    if (fichier_html == NULL)
        return -1;

    fputs(html, fichier_html);

    fclose(fichier_html);

    return 0;
}
