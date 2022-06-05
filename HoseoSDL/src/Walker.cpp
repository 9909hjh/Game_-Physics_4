#include "Walker.h"
#include <random>

// 시드값을 얻기 위한 random_device 생성.
std::random_device rd;

// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen(rd());

// 0 부터 3까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
std::uniform_int_distribution<int> dis(100, 400);

Walker::Walker()
{
    m_Vehicle.push_back(new Vehicle(100, 100));

    m_Target.push_back(new Target(dis(gen), dis(gen)));

    m_mousePos = new Vector2D(0, 0);
    target = new Vector2D(0, 0);
    steering = new Vector2D(0, 0);
    T_steering = new Vector2D(0, 0);
}

void Walker::mousemove()
{
    m_mousePos = TheInputHandler::Instance()->getMousePosition();

    //*target = *m_mousePos;
    //*m_Target = *m_mousePos;
}

void Walker::update()
{
    mousemove();

    for (int i = 0; i != m_Vehicle.size(); i++)
    {
        m_Vehicle[i]->update();
        m_Target[i]->update();

        *T_steering = m_Target[i]->Hide(m_mousePos);

        *steering = m_Vehicle[i]->arrive(T_steering);

        m_Vehicle[i]->applyForce(steering);
    }
}

void Walker::draw(SDL_Renderer* renderer)
{
    filledCircleColor(renderer, m_mousePos->getX(), m_mousePos->getY(), 10, 0xFFFFFF00);

    for (int i = 0; i != m_Vehicle.size(); i++)
    {
        m_Vehicle[i]->draw(renderer);
        m_Target[i]->draw(renderer);
    }
}
