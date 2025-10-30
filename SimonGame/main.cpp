/**
 * \author *_* and Kellen Auth
 * \date October 28, 2025
 *
 * Github usernames:
 * *_*
 * KellenAuth
 *
 * Creative Implementation:
 *  We made it so that the game only shows the most recent 5 moves,
 *  making the memorization process significantly harder. This is
 *  because it's easy to mistake the first move shown as the first
 *  move in the sequence. There is an explanation after move 5
 *  detailing this to the player.
 */

#include "mainwindow.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the model
    Model *model = new Model();

    // Create the view with the model
    MainWindow w(model);
    w.show();

    return a.exec();
}
