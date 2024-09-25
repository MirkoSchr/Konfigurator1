#include <iostream>
#include <string>
#include <map>

class FahrzeugKonfiguration {
private:
    std::string modell;
    std::string farbe;
    std::string motor;
    std::string felgen;
    std::string innenausstattung;
    std::string aussenausstattung;

    // Preise für die Features
    double basisPreis;
    std::map<std::string, double> motorPreise;
    std::map<std::string, double> felgenPreise;
    std::map<std::string, double> innenausstattungPreise;
    std::map<std::string, double> aussenausstattungPreise;

public:
    // Konstruktor
    FahrzeugKonfiguration(const std::string& m, double basisP)
        : modell(m), basisPreis(basisP) {
        // Standardpreise für die verschiedenen Features
        motorPreise = {
            {"V6 Benzin", 5000.0},
            {"V8 Benzin", 8000.0},
            {"V6 Diesel", 6000.0},
            {"Elektromotor", 10000.0}
        };

        felgenPreise = {
            {"18 Zoll Standard", 500.0},
            {"19 Zoll Sportfelgen", 1000.0},
            {"20 Zoll Chromfelgen", 1500.0}
        };

        innenausstattungPreise = {
            {"Stoff", 0.0},
            {"Leder, Schwarz", 2000.0},
            {"Leder, Beige", 2500.0}
        };

        aussenausstattungPreise = {
            {"Carbonelemente", 5000.0},
            {"Panoramadach", 2000.0},
            {"Außenspiegel-Sport", 1500.0}
        };
    }

    // Set-Methoden für die Features
    void setFarbe(const std::string& f) {
        farbe = f;
    }

    void setMotor(const std::string& mo) {
        if (motorPreise.find(mo) != motorPreise.end()) {
            motor = mo;
        } else {
            std::cout << "Ungültiger Motor gewählt!\n";
        }
    }

    void setFelgen(const std::string& fe) {
        if (felgenPreise.find(fe) != felgenPreise.end()) {
            felgen = fe;
        } else {
            std::cout << "Ungültige Felgen gewählt!\n";
        }
    }

    void setInnenausstattung(const std::string& ia) {
        if (innenausstattungPreise.find(ia) != innenausstattungPreise.end()) {
            innenausstattung = ia;
        } else {
            std::cout << "Ungültige Innenausstattung gewählt!\n";
        }
    }

    void setAussenausstattung(const std::string& aa) {
        if (aussenausstattungPreise.find(aa) != aussenausstattungPreise.end()) {
        } else {
            std::cout << "Ungültige Außenausstattung gewählt!\n";
        }
    }
            
    // Methode zur Berechnung des Gesamtpreises
    double berechneGesamtPreis() const {
        double gesamtPreis = basisPreis;

        // Preis der gewählten Features hinzufügen
        if (motorPreise.find(motor) != motorPreise.end()) {
            gesamtPreis += motorPreise.at(motor);
        }

        if (felgenPreise.find(felgen) != felgenPreise.end()) {
            gesamtPreis += felgenPreise.at(felgen);
        }

        if (innenausstattungPreise.find(innenausstattung) != innenausstattungPreise.end()) {
            gesamtPreis += innenausstattungPreise.at(innenausstattung);
        }

        if (aussenausstattungPreise.find(aussenausstattung) != aussenausstattungPreise.end()) {
            gesamtPreis += aussenausstattungPreise.at(aussenausstattung);
        }

        return gesamtPreis;
    }

    // Methode zur Darstellung der Konfiguration
    void zeigeKonfiguration() const {
        std::cout << "Fahrzeugkonfiguration:\n"
                  << "Modell: " << modell << "\n"
                  << "Farbe: " << farbe << "\n"
                  << "Motor: " << motor << " (Preis: " << motorPreise.at(motor) << " Euro)\n"
                  << "Felgen: " << felgen << " (Preis: " << felgenPreise.at(felgen) << " Euro)\n"
                  << "Innenausstattung: " << innenausstattung << " (Preis: " << innenausstattungPreise.at(innenausstattung) << " Euro)\n"
                  << "Außenausstattung: " << aussenausstattung << " (Preis: " << aussenausstattungPreise.at(aussenausstattung) << " Euro\n"
                  << "Gesamtpreis: " << berechneGesamtPreis() << " Euro\n";
    }
};

int main() {
    // Erstellen einer Fahrzeugkonfiguration mit Basispreis
    FahrzeugKonfiguration config("Audi A6", 45000.0);

    // Features setzen
    config.setFarbe("Weiß");
    config.setMotor("V6 Benzin");
    config.setFelgen("20 Zoll Chromfelgen");
    config.setInnenausstattung("Leder, Schwarz");
    config.setAussenausstattung("Carbonelemente");

    // Konfiguration anzeigen und Gesamtpreis berechnen
    config.zeigeKonfiguration();

    return 0;
}
