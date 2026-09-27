# FTL Source Layout

Where each header lives in FTL's original source tree (Subset Games' `src/`), with the classes it declares. `src/game/` in Hyperspace mirrors these folders, so a class's header here tells you which `src/game/` folder code for it belongs in.

Extracted from the DWARF debug info of **FTL 1.6.13 Steam, Linux amd64** (app `212680`, depot `221002`, `FTL.amd64` SHA-256 `23897b7e7b538da7b5858e86aed87bd2a1e567d33d12d956761099628f557d80`).

## Folders

### Root

| Header | Classes |
|---|---|
| `BossShip.h` | `BossShip` |
| `CApp.h` | `CApp` |
| `CompleteShip.h` | `CompleteShip` |

### `Debug/`

| Header | Classes |
|---|---|
| `DebugHelper.h` | `DebugHelper`, `_sig_ucontext` |

### `Gameplay/`

| Header | Classes |
|---|---|
| `AchievementTracker.h` | `AchievementTracker`, `CAchievement`, `ShipAchievementInfo` |
| `AsteroidGenerator.h` | `AsteroidGenerator` |
| `BeamWeapon.h` | `BeamWeapon` |
| `BombProjectile.h` | `BombProjectile` |
| `Collideable.h` | `Collideable`, `CollisionResponse` |
| `CrewDrone.h` | `BattleDrone`, `BoarderDrone`, `CrewDrone`, `IonDrone`, `IonDroneAnimation`, `RepairAnimation`, `RepairDrone` |
| `Damage.h` | `Damage` |
| `Drone.h` | `Drone` |
| `HackingDrone.h` | `HackingDrone` |
| `Missile.h` | `Missile` |
| `Projectile.h` | `Asteroid`, `CrewLaser`, `LaserBlast`, `PDSFire`, `Projectile` |
| `ProjectileFactory.h` | `ProjectileFactory` |
| `ScoreKeeper.h` | `CrewStatTracker`, `ScoreKeeper`, `StatTracker`, `TopScore` |
| `SpaceDrone.h` | `BoarderPodDrone`, `CombatDrone`, `DefenseDrone`, `ShipRepairDrone`, `SpaceDrone`, `SuperShieldDrone` |
| `SpaceManager.h` | `FleetShip`, `NebulaCloud`, `SpaceManager` |
| `Targetable.h` | `Targetable` |
| `TutorialManager.h` | `ArrowDescription`, `HandAnimation`, `StateInfo`, `TutorialManager` |
| `WeaponAnimation.h` | `WeaponAnimation`, `WeaponMount` |

### `Gameplay/AI/`

| Header | Classes |
|---|---|
| `CombatAI.h` | `CombatAI` |
| `CrewAI.h` | `CrewAI` |
| `ShipAI.h` | `PowerProfile`, `ShipAI` |

### `Gameplay/World/`

| Header | Classes |
|---|---|
| `BlueprintManager.h` | `AugmentBlueprint`, `Blueprint`, `BlueprintManager`, `BoostPower`, `CrewBlueprint`, `Description`, `DroneBlueprint`, `EffectsBlueprint`, `ItemBlueprint`, `MiniProjectile`, `ShipBlueprint`, `SystemBlueprint`, `SystemTemplate`, `WeaponBlueprint` |
| `EventGenerator.h` | `ChoiceTemplate`, `EventGenerator`, `EventTemplate`, `EventText`, `ResourcesTemplate`, `SectorDescription`, `ShipTemplate` |
| `EventsParser.h` | `EventsParser` |
| `GeneratorConstants.h` |  |
| `LocationEvent.h` | `BoardingEvent`, `Choice`, `ChoiceReq`, `CrewDesc`, `EventDamage`, `LocationEvent`, `ResourceEvent`, `ShipEvent`, `StatusEffect` |
| `RewardGenerator.h` | `RewardDesc` |
| `ShipGenerator.h` | `ShipGenerator` |
| `StarMap.h` | `DistressButton`, `Location`, `NebulaInfo`, `Sector`, `StarMap` |
| `WorldManager.h` | `WorldManager` |

### `Ship/`

| Header | Classes |
|---|---|
| `Algae.h` | `Algae` |
| `CrewMember.h` | `AnaerobicAlien`, `AnaerobicAnimation`, `BoardingGoal`, `CrewAnimation`, `CrewMember`, `CrewTask`, `CrystalAlien`, `CrystalAnimation`, `EnergyAlien`, `EnergyAnimation`, `EngiAlien`, `EngiAnimation`, `Ghost`, `MantisAlien`, `MantisAnimation`, `RockAlien`, `RockAnimation`, `SCrewStats`, `SlugAlien`, `SlugAnimation` |
| `CrewMemberFactory.h` | `CrewMemberFactory` |
| `CrewTarget.h` | `CrewTarget` |
| `Door.h` | `Door` |
| `Fire.h` | `Fire` |
| `Moddable.h` | `Mod`, `Moddable` |
| `Repairable.h` | `Repairable` |
| `Room.h` | `Room` |
| `Ship.h` | `DoorState`, `ExplosionAnimation`, `LockdownShard`, `Path`, `Ship` |
| `ShipGraph.h` | `ShipGraph` |
| `ShipManager.h` | `ShipManager` |
| `ShipObject.h` | `ShipInfo`, `ShipObject` |
| `Slot.h` | `Slot` |
| `Spreadable.h` | `Spreadable` |
| `Spreader.h` | `Spreader<Fire>` |

### `Ship/ShipSystems/`

| Header | Classes |
|---|---|
| `ArtillerySystem.h` | `ArtillerySystem` |
| `BatterySystem.h` | `BatterySystem` |
| `CloakingSystem.h` | `CloakingSystem` |
| `CloneSystem.h` | `CloneSystem` |
| `DroneSystem.h` | `DroneSystem` |
| `HackingSystem.h` | `HackingSystem` |
| `MindSystem.h` | `MindSystem` |
| `OxygenSystem.h` | `OxygenSystem` |
| `PowerManager.h` | `PowerManager` |
| `ShieldPower.h` | `ShieldPower` |
| `Shields.h` | `Shield`, `ShieldAnimation`, `Shields` |
| `ShipSystem.h` | `ComputerGlowInfo`, `EngineSystem`, `MedbaySystem`, `OuterHull`, `ShipSystem` |
| `TeleportSystem.h` | `TeleportSystem` |
| `WeaponSystem.h` | `WeaponSystem` |

### `UserInterface/`

| Header | Classes |
|---|---|
| `ArmamentBox.h` | `ArmamentBox` |
| `ArmamentControl.h` | `ArmamentControl` |
| `Button.h` | `Button`, `GenericButton`, `TextButton`, `ToggleButton` |
| `ChoiceBox.h` | `ChoiceBox`, `ChoiceText`, `ResourceBoxDesc` |
| `CombatControl.h` | `CombatControl` |
| `CommandGui.h` | `CommandGui` |
| `ConfirmWindow.h` | `ConfirmWindow` |
| `CreditScreen.h` | `CreditScreen` |
| `CrewBox.h` | `CrewBox` |
| `CrewControl.h` | `CrewControl` |
| `CrewManifest.h` | `CrewManifest` |
| `DroneBox.h` | `DroneBox` |
| `DroneControl.h` | `DroneControl` |
| `DropBox.h` | `DropBox` |
| `Equipment.h` | `Equipment` |
| `EquipmentBox.h` | `AugmentEquipBox`, `CrewCustomizeBox`, `CrewEquipBox`, `DroneEquipBox`, `EquipmentBox`, `EquipmentBoxItem`, `WeaponEquipBox` |
| `FTLButton.h` | `FTLButton` |
| `FocusWindow.h` | `FocusWindow` |
| `GameOver.h` | `GameOver` |
| `InfoBox.h` | `InfoBox` |
| `InputBox.h` | `InputBox` |
| `MainMenu.h` | `MainMenu` |
| `Menu.h` | `MenuScreen` |
| `MouseControl.h` | `MouseControl` |
| `NewSystemBoxes.h` | `BatteryBox`, `CloneBox`, `HackBox`, `MindBox` |
| `OptionsScreen.h` | `ControlButton`, `ControlsScreen`, `LanguageChooser`, `OptionsScreen`, `SlideBar` |
| `Selectable.h` | `Selectable` |
| `ShipBuilder.h` | `ShipBuilder` |
| `ShipRepair.h` | `ShipRepair` |
| `ShipSelect.h` | `ShipButton`, `ShipSelect`, `UnlockArrow` |
| `ShipStatus.h` | `ShipStatus` |
| `SpaceStatus.h` | `SpaceStatus` |
| `Store.h` | `Store` |
| `Storebox.h` | `AugmentStoreBox`, `CrewStoreBox`, `DroneStoreBox`, `ItemStoreBox`, `RepairStoreBox`, `StoreBox`, `SystemStoreBox`, `WeaponStoreBox` |
| `SystemBox.h` | `ArtilleryBox`, `CloakingBox`, `CooldownSystemBox`, `DoorBox`, `DroneSystemBox`, `SystemBox`, `SystemCustomBox`, `TapBoxFrame`, `TeleportBox`, `WeaponSystemBox` |
| `SystemControl.h` | `PowerBars`, `SystemControl` |
| `TabbedWindow.h` | `TabbedWindow` |
| `TextInput.h` | `TextInput` |
| `TouchTooltip.h` | `TouchTooltip` |
| `Upgrades.h` | `ReactorButton`, `UpgradeBox`, `Upgrades` |
| `WeaponBox.h` | `WeaponBox` |
| `WeaponControl.h` | `WeaponControl` |

### `Utilities/`

| Header | Classes |
|---|---|
| `Animation.h` | `Animation`, `AnimationDescriptor`, `AnimationTracker` |
| `AnimationControl.h` | `AnimationControl`, `AnimationSheet` |
| `Base.h` |  |
| `CEvent.h` | `CEvent` |
| `CFPS.h` | `CFPS` |
| `CSurface.h` | `CSurface`, `GL_Color`, `GL_ColorTexVertex`, `GL_Line`, `GL_TexVertex`, `GL_Texture` |
| `CachedImage.h` | `CachedImage` |
| `CachedPrimitive.h` | `CachedPrimitive` |
| `CachedRect.h` | `CachedRect` |
| `CachedRectOutline.h` | `CachedRectOutline` |
| `DamageMessage.h` | `DamageMessage` |
| `EventSystem.h` | `EventSystem` |
| `FileHelper.h` |  |
| `FreeType.h` | `font_data` |
| `Globals.h` | `Ellipse`, `Globals`, `RandomAmount`, `RandomNumberGenerator`, `Rect`, `TextLibrary`, `TextString`, `TimerHelper` |
| `ModControl.h` | `ModControl` |
| `ParticleEmitter.h` | `Particle`, `ParticleEmitter` |
| `Point.h` | `Point`, `Pointf` |
| `ResourceControl.h` | `DynamicImageInfo`, `ImageDesc`, `LogicalTexInfo`, `ResourceControl` |
| `Scroller.h` | `Scroller` |
| `Settings.h` | `HotkeyDesc`, `SettingValues`, `Settings` |
| `SoundControl.h` | `LoopableSound`, `SampleInfo`, `SoundControl` |
| `WarningMessage.h` | `WarningMessage`, `WarningWithLines` |
| `WindowFrame.h` | `WindowFrame` |

### `rapidxml/`

| Header | Classes |
|---|---|
| `rapidxml.hpp` | `attribute_name_pred`, `attribute_value_pred<'\\''>`, `attribute_value_pure_pred<'\\''>`, `header`, `lookup_tables<0>`, `memory_pool<char>`, `node_name_pred`, `text_pred`, `text_pure_no_ws_pred`, `whitespace_pred`, `xml_attribute<char>`, `xml_base<char>`, `xml_document<char>`, `xml_node<char>` |
| `rapidxml_print.hpp` |  |

## Regenerating

Headers come from the line tables, classes from each type's declaration file:

```sh
llvm-dwarfdump --debug-line FTL.amd64   # file_names under /Project/src/
llvm-dwarfdump --debug-info FTL.amd64   # DW_TAG_class_type / structure_type: DW_AT_name, DW_AT_decl_file
```
