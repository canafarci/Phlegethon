#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Interaction/HighlightableActor.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PHLEGETHON_API AEnemyCharacter : public ACharacterBase, public IHighlightableActor
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	//~ Start Highlightable Actor Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//~ End Highlightable Actor Interface

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	USkeletalMeshComponent* SkeletalMesh;
};
