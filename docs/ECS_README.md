# GreenCity ECS Architecture

Ce document explique comment fonctionne l’architecture ECS (Entity Component System) utilisée dans le projet **GreenCity**.

---

## 📦 Structure des dossiers

engine/
├── core/ ← Boucle principale, gestion fenêtre, moteur
├── ecs/ ← Gestion des entités, composants, systèmes
├── events/ ← Event system pour décorréler les actions
├── render/ ← Systèmes de rendu (par ex. RenderSystem)

game/
├── components/ ← Composants spécifiques au jeu (ex: Position, Building)
├── systems/ ← Systèmes de jeu (ex: ResourceSystem, HoverSystem)

---

## 🧩 Concept ECS

### 1️⃣ Entity

Une **Entity** est un identifiant unique (`uint32_t`), sans donnée attachée.
Elle sert uniquement à identifier un ensemble de composants.

---

### 2️⃣ Component

Un **Component** est une simple structure de données (POD) qui décrit un aspect d’une entité, par exemple :
- `PositionComponent` : x, y, width, height
- `BuildingComponent` : type de bâtiment, production/consommation
- `SelectableComponent` : sélectionné, survolé

Les composants n’ont **aucune logique métier**.

---

### 3️⃣ System

Un **System** est une logique qui agit sur toutes les entités ayant un certain ensemble de composants.
Exemples :
- `RenderSystem` : dessine à l’écran les entités avec Position + Building
- `ResourceSystem` : calcule les ressources globales
- `InputSystem` : capte les clics clavier/souris et envoie des événements

Chaque système a une `Signature` (bitset) indiquant quels composants il attend.

---

## ⚙️ Fonctionnement interne

### EntityManager
- Gère la création/destruction d’entités
- Réutilise les IDs détruits pour éviter de dépasser `MAX_ENTITIES`

### ComponentManager
- Enregistre les types de composants et leur assigne un `ComponentType` (uint8_t)
- Stocke les données des composants pour chaque entité
- Permet d’ajouter, retirer et récupérer des composants

### SystemManager
- Enregistre les systèmes actifs
- Maintient la liste des entités compatibles (par signature)
- Met à jour les entités quand leur signature change

---

## 🔔 Event System

Pour éviter les appels directs entre systèmes, un `EventBus` est prévu :
- Publie des événements (ex: `TileSelectedEvent`, `BuildingPlacedEvent`)
- Permet à plusieurs systèmes d’écouter et réagir sans dépendance forte

---

## 🔥 Exemple de cycle

1️⃣ L’`InputSystem` détecte un clic sur une tuile  
2️⃣ Il publie un `TileSelectedEvent` dans l’`EventBus`  
3️⃣ Le `HoverSystem` réagit en mettant à jour l’état visuel de la tuile  
4️⃣ Le `ResourceSystem` met à jour les ressources si un bâtiment est placé  
5️⃣ Le `RenderSystem` dessine tout à la frame suivante

---

## ✅ Avantages

✅ Architecture décorrélée et modulaire  
✅ Plus facile à tester et étendre  
✅ Peut évoluer vers du multithreading si besoin  
✅ Prépare le code pour gérer des entités plus complexes (habitants, réseaux, etc.)

---

## 📊 Tests unitaires

Des tests Criterion sont prévus pour :
- `EntityManager`
- `ComponentManager`
- `SystemManager`

Ils valident la robustesse de l’ECS de base.

---

## 🚀 À venir

- Passage complet de la logique de jeu actuelle en ECS
- Ajout de systèmes avancés (UI, son, IA)
- Optimisation des allocations et accès mémoire

---