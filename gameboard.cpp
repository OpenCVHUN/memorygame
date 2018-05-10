#include "gameboard.h"
#include "card.h"

#include <vector>
#include <QTime>
#include <QGraphicsDropShadowEffect>

GameBoard::GameBoard()
    : m_rows(2)
    , m_columns(8)
{
    qsrand(static_cast<quint32>(QTime::currentTime().msec()));

    int cards = m_rows * m_columns;
    std::vector<char> letters;
    char first = 'A';
    char last = 'A' + static_cast<char>(cards) - 1;

    for (int i = 0; i < cards; i++) {
        char l = first + (qrand() % (last - first));
        letters.push_back(l);
    }

    int cardWidth = 100;
    int cardHeight = 170;
    int margin = 10;

    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_columns; j++) {
            char c = letters[0];
            letters.erase(letters.begin());
            Card *card = new Card(c, cardWidth, cardHeight);
            card->setPos(QPointF((cardWidth + margin) * j, (cardHeight + margin) * i));

            QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
            effect->setColor(QColor(0, 0, 0, 200));
            effect->setOffset(0);
            effect->setBlurRadius(12);
            card->setGraphicsEffect(effect);

            this->addItem(card);
        }
    }
}

void GameBoard::startGame()
{

}

void GameBoard::endGame()
{

}
