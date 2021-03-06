#ifndef TURM_HPP
#define TURM_HPP

class Turm : Figur {
    
    private:
    
    public:
    
        Turm();
        Turm(int coll, int row, bool color, SVG *view);
    
        void showMovement(Schachbrett *brett);
        void setPos(int coll, int row);
    
};

Turm::Turm() {
    
    this->row = 0;
    this->coll = 0;
    
};

Turm::Turm(int coll, int row, bool color, SVG *view) {
    
    this->row = row;
    this->coll = coll;
    this->color = color;
    
    if (color) {
        pic = new Image("Bilder/White/tower.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    } else { 
        pic = new Image("Bilder/Black/tower.png", coll * 60 + 40, 610 - row * 60 - 30, 60, 60, view);
    }
    
};

// siehe Dame
void Turm::showMovement(Schachbrett *brett) {
    
    bool endO = false;
    bool endU = false;
    bool endR = false;
    bool endL = false; 
    
    for (int i = 1; i < 8; i++) {
        
        if ((brett->getTileFig(coll, row + i - 1)[2] == 'b' && color) || (brett->getTileFig(coll, row + i - 1)[2] == 'w' && !color) ||
           (brett->getTileFig(coll, row + i)[2] == 'b' && !color) || (brett->getTileFig(coll, row + i)[2] == 'w' && color) || (row + i) > 8)
            endO = true;
        
        if ((brett->getTileFig(coll, row - i + 1)[2] == 'b' && color) || (brett->getTileFig(coll, row - i + 1)[2] == 'w' && !color) ||
           (brett->getTileFig(coll, row - i)[2] == 'b' && !color) || (brett->getTileFig(coll, row - i)[2] == 'w' && color) || (row - i) < 1)
            endU = true;
        
        if ((brett->getTileFig(coll + i - 1, row)[2] == 'b' && color) || (brett->getTileFig(coll + i - 1, row)[2] == 'w' && !color) ||
           (brett->getTileFig(coll + i,row)[2] == 'b' && !color) || (brett->getTileFig(coll + i, row)[2] == 'w' && color) || (coll + i) > 8)
            endR = true;
        
        if ((brett->getTileFig(coll - i + 1, row)[2] == 'b' && color) || (brett->getTileFig(coll - i + 1, row)[2] == 'w' && !color) ||
           (brett->getTileFig(coll - i,row)[2] == 'b' && !color) || (brett->getTileFig(coll - i, row)[2] == 'w' && color) || (coll - i) < 1)
            endL = true;        
        

        if (!endO) {  
            
            brett->setPM(coll, row + i);
            brett->colorTile(coll, row + i, "green");
            
        }
       
        if(!endU) {   
            
            brett->setPM(coll, row - i);
            brett->colorTile(coll, row - i, "green");
            
        }
       
        if(!endR) {  
            
            brett->setPM(coll + i, row);
            brett->colorTile(coll + i, row, "green");
            
        }
        
        if(!endL) { 
            
            brett->setPM(coll - i, row);
            brett->colorTile(coll - i, row, "green");
            
        }
        
        
        
    }
    
};

void Turm::setPos(int coll, int row) {
    
    this-> row = row;
    this-> coll = coll;
    pic->moveTo(coll * 60 + 40, 610 - row * 60 - 30);
    
};

#endif