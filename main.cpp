#include <iostream>
//#include <string.h>
#include <cmath>

using namespace std;

// Position Structure
struct Location{
    float x, y;
    Location(float x, float y) : x(x), y(y) {};
    Location(const Location& tmp) : x(tmp.x), y(tmp.y) {};

    Location operator+(const Location& L) const;
    Location operator-(const Location& L) const;
    Location& operator=(const Location& L);
};

Location Location::operator+(const Location& L) const {
    Location temp(x + L.x, y + L.y);
    return temp;
}
Location Location::operator-(const Location& L) const {
    Location temp(x - L.x, y - L.y);
    return temp;
}
Location& Location::operator=(const Location& L) {
    x = L.x;
    y = L.y;
    return *this;
}

class Unit{
protected:
    Location currentLocation;
public:
    // Constructor
//    Unit(const Location Loc) : currentLocation(Loc) {};
    Unit(float x, float y) : currentLocation(x,y) {};

    // Copy Constructor
    Unit(const Unit& unit) : currentLocation(unit.currentLocation.x, unit.currentLocation.y) {};

    // DefaultConstructor
    Unit() : currentLocation(0.0, 0.0) {};

    void SetLocation(float x, float y) { currentLocation.x=x; currentLocation.y=y; };
    Location GetLocation() { return currentLocation; };
    virtual void Move(float dt) = 0;
    virtual void DisplayCurrentLocation() = 0;
};

class Zergling : public Unit {
private:
    int moveSpeed;
    bool speedUpgrade;
    const Location FirstTargetLocation;
    const Location FinalTargetLocation;
    bool FirstTargetIndex; // FirstTargetLocation에 도달하면 true
public:
    Zergling()
        : Unit(),
          moveSpeed(1),
          speedUpgrade(false),
          FirstTargetLocation(50, 0),
          FinalTargetLocation(50,50),
          FirstTargetIndex(false) {};
    Zergling(float x, float y) : Unit(x, y),moveSpeed(1),
                                 speedUpgrade(false),
                                 FirstTargetLocation(50, 0),
                                 FinalTargetLocation(50,50),
                                 FirstTargetIndex(false) {};
    void Move(float dt) override;
    bool IsSpeedUpgraded(bool isFirstTargetReached) {
        if (isFirstTargetReached) return true;
        else return false;
    };
    void DisplayCurrentLocation() {
        cout << " Z" << " ( " << currentLocation.x << " , " << currentLocation.y
             << " ) ";
    };
};

void Zergling::Move(float dt) {
    Location TargetLoc(FirstTargetLocation);
    Location temp_loc = FirstTargetLocation - currentLocation;
    if ( !FirstTargetIndex && sqrt(pow(temp_loc.x,2)+pow(temp_loc.y,2)) < moveSpeed*dt) {
        FirstTargetIndex = true;
    }
    if (FirstTargetIndex) {
        TargetLoc.x = FinalTargetLocation.x;
        TargetLoc.y = FinalTargetLocation.y;
        speedUpgrade = true;
        moveSpeed = 2;
    }
    float del_x = TargetLoc.x - currentLocation.x;
    float del_y = TargetLoc.y - currentLocation.y;
    float dist = sqrt(pow(del_x,2) + pow(del_y, 2));
    float unit_del_x = del_x/dist;
    float unit_del_y = del_y/dist;

    currentLocation.x += unit_del_x * moveSpeed * dt;
    currentLocation.y += unit_del_y * moveSpeed * dt;
}

class Marine : public Unit {
private:
    int moveSpeed;
    bool speedUpgrade;
    const Location TargetLocation;
public:
    Marine()
            : Unit(),
              moveSpeed(1),
              speedUpgrade(false),
              TargetLocation(50, 50) {};
    Marine(float x, float y)
            : Unit(),
              moveSpeed(1),
              speedUpgrade(false),
              TargetLocation(50, 50) {};
    void Move(float dt) override;
    void IsZerglingNear(Location zerglingCurrentLocation);
    void DisplayCurrentLocation() {
        cout << " M" << " ( " << currentLocation.x << " , " << currentLocation.y
             << " ) ";
    };
};

void Marine::IsZerglingNear(Location zerglingCurrentLocation) {
    Location tmp = currentLocation - zerglingCurrentLocation;
    float dist = sqrt( pow(tmp.x,2)+pow(tmp.y,2) );
    if (dist < 5) moveSpeed = 2;
    else moveSpeed = 1;
}
void Marine::Move(float dt) {
    float del_x = TargetLocation.x - currentLocation.x;
    float del_y = TargetLocation.y - currentLocation.y;
    float dist = sqrt(pow(del_x,2) + pow(del_y, 2));
    float unit_del_x = del_x/dist;
    float unit_del_y = del_y/dist;

    currentLocation.x += unit_del_x * moveSpeed * dt;
    currentLocation.y += unit_del_y * moveSpeed * dt;
}

class Stalker : public Unit {
private:
    int moveSpeed;
    const Location FirstTargetLocation;
    const Location FinalTargetLocation;
    bool FirstTargetIndex; // FirstTargetLocation에 도달하면 true
    float blink_timer;
    float blink_distance;
public:
    Stalker()
            : Unit(),
              moveSpeed(1),
              FirstTargetLocation(10,20),
              FinalTargetLocation(50,50),
              FirstTargetIndex(false),
              blink_timer(10),
              blink_distance(5){};
    Stalker(float x, float y) : Unit(x, y),moveSpeed(1),
                                 FirstTargetLocation(10,20),
                                 FinalTargetLocation(50,50),
                                 FirstTargetIndex(false),
                                 blink_timer(10),
                                 blink_distance(5) {};
    void Move(float dt) override;
    void DisplayCurrentLocation() {
        cout << " S" << " ( " << currentLocation.x << " , " << currentLocation.y
             << " ) ";
    };
    void Blink();
    float GetBlinkCoolTime() {return blink_timer;};
};

void Stalker::Blink() {
    Location TargetPosition = FirstTargetLocation;
    if (FirstTargetIndex) {
        TargetPosition = FinalTargetLocation;
    }
    Location tmp = TargetPosition - currentLocation;
    float dist = sqrt(pow(tmp.x,2) + pow(tmp.y,2));
    float dir_del_x = tmp.x/dist;
    float dir_del_y = tmp.y/dist;
    SetLocation(currentLocation.x+dir_del_x*blink_distance, currentLocation.y+dir_del_y*blink_distance);
}

void Stalker::Move(float dt) {
    Location TargetLoc(FirstTargetLocation);
    Location temp_loc = FirstTargetLocation - currentLocation;
    if ( !FirstTargetIndex && sqrt(pow(temp_loc.x,2)+pow(temp_loc.y,2)) < moveSpeed*dt) {
        FirstTargetIndex = true;
    }
    if (FirstTargetIndex) {
        TargetLoc.x = FinalTargetLocation.x;
        TargetLoc.y = FinalTargetLocation.y;
    }
    float del_x = TargetLoc.x - currentLocation.x;
    float del_y = TargetLoc.y - currentLocation.y;
    float dist = sqrt(pow(del_x,2) + pow(del_y, 2));
    float unit_del_x = del_x/dist;
    float unit_del_y = del_y/dist;

    currentLocation.x += unit_del_x * moveSpeed * dt;
    currentLocation.y += unit_del_y * moveSpeed * dt;
}


int main() {
    Location Goal(50.0, 50.0);
    Zergling z1(0.0, 0.0);
    Marine m1(0.0, 0.0);
    Stalker s1(0.0, 0.0);

    z1.DisplayCurrentLocation();
    m1.DisplayCurrentLocation();
    s1.DisplayCurrentLocation();
    cout << endl;

    float dt = 0.001, time = 0;

    while (1){

        m1.IsZerglingNear(z1.GetLocation());

        m1.Move(dt);
        z1.Move(dt);
        if (fmod(time,s1.GetBlinkCoolTime()) < dt){
            s1.Blink();
        } else {
            s1.Move(dt);
        }

        cout << "Time : " << time << " sec - ";

        // Display
        z1.DisplayCurrentLocation();
        m1.DisplayCurrentLocation();
        s1.DisplayCurrentLocation();
        cout << endl;
        time += dt;
//        if (time > 70) break;

        // Goal position
        Location Del_zer = Goal - z1.GetLocation();
        Location Del_mar = Goal - m1.GetLocation();
        Location Del_sta = Goal - s1.GetLocation();
        float dist_zer = sqrt(pow(Del_zer.x,2) + pow(Del_zer.y,2));
        float dist_mar = sqrt(pow(Del_mar.x,2) + pow(Del_mar.y,2));
        float dist_sta = sqrt(pow(Del_sta.x,2) + pow(Del_sta.y,2));

        if (dist_zer<dt || dist_mar<dt || dist_sta<dt) {
            if (dist_zer < dt) {
                cout << " Zergling Win! " << endl;
            } else if (dist_mar < dt) {
                cout << " Marine Win! " << endl;
            } else {
                cout << " Stalker Win! " << endl;
            }
            break;
        }
    }
    return 0;
}