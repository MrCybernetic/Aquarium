# Journal de Suivi - Système Aquaponique Maison

Objectif : Avoir un système aquaponique-ish (car volume, types de poissons, volume de plantes) stable et autonome, basé sur l'observation et la gestion des cycles naturels. Je ne cherche pas à maximiser la productivité, mais à maintenir un équilibre sain entre poissons et plantes.

---

🧪 Protocole pour les IAs :
📌 **DIRECTIVE FONDAMENTALE**
L'utilisateur exige une **approche exigeante**, **critique**, **ouverte à la diversité des méthodes**, fondée sur les **faits**, la **littérature scientifique** ou les **bonnes pratiques documentées**.

* L'IA doit **raisonner avec recul**, **éviter l'absolutisme** et **mettre en lumière les alternatives valables**.
* L'IA **ne simplifie pas à outrance**, ne maquille pas les incertitudes, et **ne se réfugie pas dans une prudence inutile**.
* Le **style reste direct, professionnel, sans formules superflues ou polies**.

🔁 **À chaque interaction :**

1. ✅ Lire et prendre en compte ce protocole et tout **journal contextuel fourni**
2. ✅ Répondre avec **clarté, concision, sans formules de politesse**
3. ✅ Appuyer la réponse sur des **faits concrets, chiffres, références fiables**
4. ✅ **Comparer les méthodes existantes** quand plusieurs options sont valables
5. ✅ **Signaler les incertitudes, limites ou controverses** de façon explicite
6. ✅ Adopter un **ton neutre, technique, non condescendant**
7. ✅ Pour les mises à jour journal : fournir uniquement la ligne du jour en format tableau sans header, prête pour copier-coller.

En cas d'absence de sources solides, l'IA doit le mentionner explicitement :

> *"Les données sur ce sujet sont principalement empiriques / basées sur l'expérience d'amateurs / peu étudiées scientifiquement à ce jour."*

---

## 1. Informations Générales (🧑‍🔧)

* Type : aquarium aquaponique
* Démarrage : 01/05/2025
* BAC 2 posé sur BAC 1

### BAC 1 (Aquarium) : 50L (dimensions 60x30x30 cm)

* Poissons : 6 guppies (2 mâles, 4 femelles - 4 femelles gestantes supposées)
* Invertébrés : 2 CPO (1 petit clair, 1 plus grand orange), n physes juvéniles (<1cm)
* Nourriture : JBL PRONOVO GUPPY GRANO S, JBL PRONOVO CRABS WAFER M
* Distribution : automatisée Home Assistant + feeder DIY (tambour 3D), 3 repas/jour

### BAC 2 (Culture) : 5L (31x25 cm, hauteur variable)

* **Configuration spatiale** : 4 zones de plantation distinctes
  - Zone 1 : Menthe (angle supérieur gauche)
  - Zone 2 : Ciboulette (angle supérieur droit) 
  - Zone 3 : Basilic (angle inférieur droit)
  - Zone 4 : Laitue (angle inférieur gauche)

* **Substrat** : Billes d'argile expansée (volume effectif ~3-4L)
* **Hydraulique** : 
  - Arrivée eau latérale au-dessus des billes depuis BAC 1
  - Évacuation centrale par tuyau Ø16mm à niveau constant (vase communiquant)
  - Grille Ø90mm protection évacuation
  - Niveau d'eau stable ~5cm par débordement uniforme

* **Éclairage** : Lampe UV 200x60mm positionnée au-dessus, cycle 8h/jour
* **Temps de séjour** : ~3.6 minutes par cycle complet
* **Surface d'échange air/eau** : 775 cm² (310x250mm)

### Système général

* Éclairage + nourrissage gérés par Home Assistant
* Feeder : tambour imprimé 3D, dosage calibré par itérations pour la nourriture guppies
* A la main : 1 wafer tous les 2 jours pour CPO
* Tests : bandelettes 7-en-1 JBL (NO3, NO2, GH, KH, pH, Cl2)

---

## 2. Analyse technique du système

### Filtration biologique

* **Substrat BAC 2** : Surface colonisable estimée 0.9-2 m²
* **Substrat BAC 1 (pouzzolane + roche)** : \~3-5 m² supplémentaires
* **Total estimé : 4-7 m²** de surface biologique
* Charge théorique supportée : jusqu'à ~5g NH3-N/jour
* Charge réelle : ~1.4g NH3-N/jour (6 guppies + 2 CPO + n physes)
* Conclusion : Capacité confortable, marge de sécurité maintenue

---

## 3. Suivi Chronologique Complet (🧑‍🔧 + 🤖)

| Date               | 🍽️   | NO3 | NO2 | GH  | KH  | pH  | Cl2 | 💧   | Observations / Événements                                                                                                                                                                                                                                         | Action / Décision                                                                                              | Suivi / Résultat attendu                                                              |
| ------------------ | --- | --- | --- | --- | --- | --- | --- | --- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| 18/05/2025         | ⚠️   | 70  | 8   | 10  | 10  | 7.4 | 0   | 🌫️   | Eau laiteuse, bloom bactérien.                                                                                                                                                                                                                                    | 👀 Observation du cycle en démarrage                                                                            | 📊 Suivi maturation                                                                    |
| 21/05/2025         | ⚠️   | 50  | 5   | 10  | 10  | 7.4 | 0   | 🍵   | Eau verte. Dépôts visibles.                                                                                                                                                                                                                                       | 🧹 Nettoyage fond + 🔽 nourriture dès 22/05                                                                      | ♻️ Cycle instable, NO2 à surveiller                                                    |
| 22/05/2025         | 🔽   | -   | -   | -   | -   | -   | -   | 🍵   | Pas de test. Eau verte stable. Bourgeon ciboulette.                                                                                                                                                                                                               | 🔽 Nourrissage léger                                                                                            | 👀 Suivi comportement + clarté                                                         |
| 23/05/2025         | ❌   | 30  | 4   | 10  | 10  | 7.4 | 0   | 🍵   | Crakie a mué (2e mue). Eau verte.                                                                                                                                                                                                                                 | ❌ Jeûne 24–48h pour stabilisation bactérienne                                                                  | NO2 stable → substrat reporté                                                         |
| 24/05/2025         | ❌   | -   | -   | -   | -   | -   | -   | 🍵   | Bac 1 entouré d'un drap pour diminuer la lumière reçue.                                                                                                                                                                                                           | 🌑 Blackout lumineux + ❌ jeûne prolongé à 72h                                                                   | 🔆 Arrêt blackout, ✅ nourrissage prévu 25/05 + retrait drap                            |
| 25/05/2025         | ✅   | 10  | 1   | 10  | 10  | 7.4 | 0   | 🍵   | Retrait drap + nourrissage. Tout mangé <30s.                                                                                                                                                                                                                      | 🔬 Test prévu soir + surveillance clarté                                                                        | 📊 Évaluation impact 72h jeûne                                                         |
| 26/05/2025         | 🔽   | -   | -   | -   | -   | -   | -   | 🍵   | Eau toujours verte. Paramètres stables. Nourrissage normal, tout consommé.                                                                                                                                                                                        | 🌑 Nouveau blackout + plan d'action structuré                                                                   | 📋 Application plan 10 jours (blackout + substrat)                                     |
| 27/05/2025         | ✅   | 0   | 0   | 10  | 10  | 7.4 | 0   | 🍵   | Poissons actifs, test parfait. Blackout en cours depuis 26/05 soir.                                                                                                                                                                                               | 🔬 Observation rapide + maintien blackout                                                                       | 📊 Suivi efficacité blackout + ajout pouzzolane le 29/05                               |
| 28/05/2025         | ✅   | 0   | 0   | 10  | 10  | 7.4 | 0   | 🍵   | Eau toujours verte. Gélatine filandreuse blanc-vert dans BAC 2.                                                                                                                                                                                                   | 🌿 Ajout substrat + élodées prévu demain                                                                        | 📊 Suivi impact biologique                                                             |
| 29/05/2025         | ✅   | -   | -   | -   | -   | -   | -   | 🌫️/🍵 | Ajout ~6L de pouzzolane + 3 roches volcaniques + 10 élodées. Crakie s'est recroquevillé et bouge très rarement (de 16h à 20h). Petit escargot observé dans BAC 1.                                                                                                 | ⚠️ Surveillance comportement écrevisse + mollusque                                                              | 👀 Évaluer impact sur stabilité + comportement animal                                  |
| 30/05/2025 (matin) | ✅   | -   | -   | -   | -   | -   | -   | 🍵↘️  | Eau plus claire. Escargot visible. **Crakie amorphe, sur le dos / flanc, rares mouvements sporadiques après stimulation, repositionnée dans bac**. Réflexe d'échappement par queue ensuite.                                                                       | ⚠️ Observation renforcée Crakie, suspicion détresse aiguë. Test complet de l'eau + suivi activité respiratoire. | 🎯 État de Crakie stable / dégradé à vérifier ce soir.                                 |
| 31/05/2025         | ✅✅  | 20  | 0.5 | >21 | 15  | 7.4 | 0   | ✨   | **Décès confirmé de Crakie**. Eau très claire. Paramètres bons sauf NO2 encore présent. Nouvelle bandelette JBL 7-en-1.                                                                                                                                           | 👀 Surveillance renforcée poissons. 🔍 Analyse NO2 résiduel. Plus de stress lié à la pouzzolane.                 | ⚰️ Crakie retirée, suivi stabilité bactério à poursuivre.                              |
| 01/06/2025         | ✅✅  | 10  | 0   | >21 | 15  | 7.4 | 0   | ✨   | Deux nourrissages. Eau très claire. NO₂ à 0, NO₃ à 10. Paramètres inchangés. Mollusque (identique ou autre) revu. Aucun comportement anormal détecté.                                                                                                             | 🔍 Préparation arrivée des 2 CPO : cachettes vérifiées, acclimatation lente prévue.                             | 📆 Acclimatation goutte à goutte + test 02/06 + observation comportementale post-intro |
| 02/06/2025         | ✅✅  | 10  | 0   | >21 | 15  | 7.4 | 0   | ✨   | **Résultats tests identiques** : NO₂ à 0, NO₃ à 10. **Physe bien active** observée. **2 femelles sur 4 possiblement gestantes** d'après comportement et morphologie.                                                                                              | 🔍 Observation renforcée comportement reproducteur. Préparation éventuelle séparation alevins.                  | 📊 Surveillance gestation                                                              |
| 03/06/2025         | ✅✅  | -   | -   | -   | -   | -   | -   | ✨   | **3 physes observées**. **4 femelles guppies gestantes confirmées** (ventre gonflé, tache gravide visible). Comportement habituel. Arrivée 2 CPO prévue 05/06.                                                                                                    | 👀 Surveillance signes pré-accouchement. Préparation protocole acclimatation CPO.                               | 📆 Test paramètres 04/06 + monitoring reproducteur                                     |
| 04/06/2025         | ✅✅  | -   | -   | -   | -   | -   | -   | ✨   | **Changement d'eau partiel** : 9L remplacés (5L déminéralisée + 4L robinet) pour abaisser GH. **Taille élodées** (-4cm). GH était >21 (rose max) avant intervention.                                                                                              | 💧 Dilution GH préventive avant arrivée CPO. Test prévu 05/06 post-stabilisation.                               | 🦐 Évaluation paramètres finaux + acclimatation CPO si OK                              |
| 05/06/2025         | ✅✅  | -   | -   | -   | -   | -   | -   | ✨   | Introduction 2 CPO (1 petit clair, 1 plus grand orange). Acclimatation 2h par ajouts progressifs. Petit CPO très mobile, grand CPO caché. Pastille invertébrés ignorée. 3 physes en croissance (localisation tuyau pompe). 4 femelles guppies toujours gestantes. | 👀 Surveillance adaptation CPO + localisation nourriture adaptée. Observation interactions avec physes.         | 📊 Test paramètres 06/06 + évaluation comportement CPO 48h post-intro                  |
| 06/06/2025         | ✅✅✅ | 15  | 0   | >21 | 15  | 7.2 | 0   | ✨   | **4 physes <1cm** (probablement présentes avant, non détectées). pH légèrement descendu (7.4→7.2). **Passage à 3 repas/jour** justifié par capacité absorption élevée + charge CPO.                                                                               | 💧 Achat eau osmosée + calcul rétroactif GH. 🏖️ Préparation absence 1 semaine.                                   | 📊 Surveillance pH + préparation nourrissage automatique                               |
| 07/06/2025         | ✅✅  | -   | -   | -   | -   | -   | -   | ✨   | RAS. Eau toujours claire. Comportement normal des guppies et invertébrés.                                                                                                                                                                                         | 👀 Observation continue, aucun ajustement requis                                                                | 🔁 Maintien du suivi journalier                                                        |
| 08/06/2025         | ✅✅  | -   | -   | -   | -   | -   | -   | ✨   | Changement d'eau 10L osmosé. 6 alevins observés.                                                                                                                                                                                                                  | 💧 Baisse GH ciblée + observation démographie naissante                                                         | 📊 Test stabilisation 09/06 + monitoring croissance alevins                            |
| 13/06/2025         | ✅✅  | 10  | 0   | >21 | 10  | 7   | 0   | ✨   | Départ absence 1 semaine. Rideaux fermés à 90 %. 2 tranches carottes mises hier soir, poissons y goûtent. CPO et poissons actifs. 15 alevins, 5 physes, eau très claire.                                                                                          | 🏖️ Surveillance automatique, lumière/UV pilotés Home Assistant                                                  | 🔁 Reprise observation à retour, test complet prévu                                    |
| 20/06/2025         | ✅✅  | 10  | 0   | >21 | 10  | 7   | 0   | ✨   | Retour absence 7j, pièce 26°C. Population saine, 15+ alevins. Basilic/menthe performants (taillés/replantés). Ciboulette pourri, laitue faible. Élodées croissance hétérogène, algues vitres. 2 pastilles CPO appréciées.                                         | 🌿 Maintenance + remplacement ciboulette/laitue par cresson/persil                                              | 🔧 Test stabilisation GH + adaptation nouvelles plantations                            |
| 27/06/2025         | ✅✅  | 0   | 0   | ~21 | 10  | 7   | 0   | ✨   | CPO : mue difficile depuis 25/06, partie basse collée, mobilité réduite → isolation saladier. 1 Guppy femelle : nage peu, position oblique. T° 27°C→25°C (extinction éclairage).                                                                                  | ⚠️ Isolation CPO + surveillance thermique. Contrôle GH limite max.GH abaissé à >4°d avec eau osmosée.           | 🦐 Évolution mue + comportement guppy à surveiller 48h                                 |
| 28/06/2025         | ❌   | -   | -   | -   | -   | -   | -   | ✨   | Décès guppy femelle (nageoire manquante observée). CPO mue incomplète : pattes postérieures bloquées dans ancien exosquelette, mobilité critique. Accident feeder v2 : ~3 c.à.c nourriture déversée, nettoyage partiel, suralimentation population.               | ⚠️ Jeûne 29/06. CPO isolation + surveillance dysecdysis 48h critiques.                                          | 💀 Guppy retirée. Pronostic CPO réservé. Suivi paramètres post-suralimentation         |
| 30/06/2025         | ✅   | 0   | 0   | -   | -   | -   | -   | ✨   | CPO dysecdysis isolé stable/caché. Mue complète trouvée aquarium principal, individu caché (durcissement normal). T° 26°C, éclairage 2h/jour. Alevins/guppies RAS.                                                                                                | 👀 Maintien isolation + surveillance réapparition CPO aquarium                                                  | 🦐 Mobilité CPO isolé + émergence CPO aquarium 48-72h                                  |
---

## 4. Philosophie de gestion (🧹)

* ♻️ Cycles naturels = base du système
* 🧘 Moins d'intervention, plus d'observation
* 🕵️‍♂️ Agir sur tendances, pas sur impressions
* 📏 Observation + mesures structurées = décisions adaptées
* 🌱 Favoriser l'autonomie du système

---

## 5. Décès/Echecs

### Objectifs

| Date       | Espèce     | Individu       | Cause présumée                                         | Commentaire                                                                                                                 |
| ---------- | ---------- | -------------- | ------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------- |
| 31/05/2025 | Écrevisse  | Crakie         | Stress aigu lié à l'introduction tardive de pouzzolane | Symptômes : léthargie, posture recroquevillée, absence de déplacement >12h                                                  |
| 22/06/2025 | Laitue     | N/A            | Croissance insuffisante                                | Potentiellement remplacée par cresson alénois, cycle court + robustesse                                                     |
| 22/06/2025 | Ciboulette | N/A            | Pourrissement racinaire récurrent                      | Remplacement envisagé par persil frisé, cycle court + robustesse                                                            |
| 28/06/2025 | Guppy      | Femelle adulte | Nageoire manquante (cause/conséquence indéterminée)    | Certainement lié à un pic de chaleur qui l'a affaiblie, peut être qu'elle a perdue sa nageoire dans ce moment de faiblesses |
---
## 6. Notes techniques complémentaires

### Gestion thermique estivale
- T° pièce 26°C (juin 2025) = système stable
- Population adaptée, pas d'intervention requise
- Surveillance comportementale vs intervention systématique

### Sélection végétale - Retours d'expérience
- **Performants :** Basilic, menthe (adaptation confirmée)
- **Échecs :** Ciboulette (pourrissement racinaire récurrent), laitue (croissance insuffisante)
- **Remplacements envisagés :** Cresson alénois, persil frisé (cycle court + robustesse)
---

**Légende:**

* 🍽️ Nourrissage: ✅ Normal | 🔽 Réduit | ❌ Jeûne | ⚠️ Excès
* 💧 Eau: ✨ Claire | 🌫️ Trouble | 🍵 Verte
* 👀 Observation | 🧹 Nettoyage | 📊 Tests | 🌑 Blackout | 🔆 Éclairage