//
// Created by Elias Aggergaard Larsen on 04/01/2025.
//

#ifndef GUIELEMENT_H
#define GUIELEMENT_H


class GUIElement
{
public:
    GUIElement() = default;
    virtual ~GUIElement() = 0;
    virtual void draw() = 0;

    [[nodiscard]] int getID() const
    {
        return id_;
    }
    void setID(const int id)
    {
        id_ = id;
    }

private:
    int id_{};
};



#endif //GUIELEMENT_H
