# 📄 Cahier des charges – Jeu "Green City"

## 🎮 Résumé du jeu

**Green City** est un jeu de stratégie/gestion en C++ inspiré de *Clash of Clans*, avec une vue isométrique. Le joueur incarne un architecte/maire chargé de construire et développer une ville la plus écologique possible. Il doit gérer les ressources naturelles (eau, électricité), choisir les bonnes infrastructures et limiter la pollution tout en faisant croître sa ville. Le défi est de trouver un équilibre entre expansion rapide et durabilité environnementale.

---

## 🧹 Fonctionnalités principales

### 🔹 Vue et interface
- Vue isométrique (2D ou fausse 3D)
- Carte quadrillée (grid-based)
- HUD avec ressources, éco-score, pollution, temps
- Sélection / placement de bâtiments par clic

### 🔹 Système de ressources
- **Eau** : source naturelle, récupération de pluie, stations de traitement
- **Électricité** : renouvelable (éolienne, solaire, hydraulique) ou polluante (charbon, gaz)
- **Matériaux** : bois, métal, plastique (recyclé ou non)
- **ÉcoPoints** : score de durabilité écologique

### 🔹 Types de bâtiments
| Catégorie | Exemples | Impact |
|-----------|----------|--------|
| Habitats  | Maison, HLM, éco-habitat | Consomment énergie et eau |
| Production d’énergie | Éolienne, solaire, charbon | Fournissent énergie mais polluent ou pas |
| Services publics | Recyclage, traitement eau, transports | Améliorent éco-score |
| Décoration | Arbres, parcs | Réduisent pollution visuelle et augmentent bonheur |

### 🔹 Gestion environnementale
- Indicateurs de pollution : air, sol, eau
- Système météo : pluie = bonus pour récupération, canicule = surconsommation
- Crises écologiques : pannes, sécheresse, pics de pollution

### 🔹 Arbre technologique
- Nouvelles technologies à débloquer avec XP ou temps : panneaux solaires avancés, toits végétalisés, bus électriques, etc.

### 🔹 Boucle de jeu
1. Placement de bâtiments
2. Consommation / production des ressources
3. Réactions en chaîne (pollution, crise, bonus…)
4. Déblocage de nouvelles options
5. Évolution de la ville + évaluation écologique

---

## ⚙️ Fonctionnement technique (backend)

### 🔸 Langage : **C++**
### 🔸 Librairies possibles :
- **SFML** pour la 2D + son + input (a voir)
- **ImGui** pour l’interface debug (facultatif)
- **JSON** pour les sauvegardes

### 🔸 Composants techniques :
| Composant | Description |
|----------|-------------|
| `MapManager` | Gère la carte, les tuiles, les zones constructibles |
| `Building` | Classe générique pour les bâtiments |
| `ResourceManager` | Gère la production/consommation des ressources |
| `GameLoop` | Boucle principale (render, update, input) |
| `UIManager` | Gère les menus, HUD, sélection… |
| `TechTree` | Arbre technologique dynamique |

---

## 📊 Indicateurs & objectifs

| Indicateur | Description |
|------------|-------------|
| ÉcoPoints  | Score global de la ville, évolue selon les décisions |
| Population | Grandit selon le nombre de maisons et services |
| Pollution  | Répartie en air / eau / sol, impacte l’évolution |
| Niveau de ville | Débloque de nouvelles constructions et techs |

---

## 🔮 Évolutions possibles
- Mode campagne avec missions (ex : survivre à 5 sécheresses)
- Système de citoyens individuels avec IA basique
- Interactions avec la nature (faune, flore)

---

## 📦 Livrables
- Fichiers sources du jeu (C++)
- Executable Windows/Linux/MacOs (selon plateforme choisie)
- Fichier de sauvegarde (JSON ou autre)
- Document de design + manuel utilisateur