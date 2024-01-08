#include "Actor/PhlegethonEffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/PhlegethonAttributeSet.h"
#include "Components/SphereComponent.h"

APhlegethonEffectActor::APhlegethonEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void APhlegethonEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &APhlegethonEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &APhlegethonEffectActor::EndOverlap);
}

void APhlegethonEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APhlegethonEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                       UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                       const FHitResult& SweepResult)
{
	//TODO change this to a GameplayEffect. This is for debug only
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAttributeSet* AttributeSet = ASCInterface->GetAbilitySystemComponent()->
		                                                  GetAttributeSet(UPhlegethonAttributeSet::StaticClass());
		const UPhlegethonAttributeSet* PhlegethonAttributeSet = Cast<UPhlegethonAttributeSet>(AttributeSet);

		UPhlegethonAttributeSet* MutablePhlegethonAttributeSet = const_cast<UPhlegethonAttributeSet*>(
			PhlegethonAttributeSet);

		MutablePhlegethonAttributeSet->SetHealth(PhlegethonAttributeSet->GetHealth() + 25.f);
		MutablePhlegethonAttributeSet->SetMana(PhlegethonAttributeSet->GetMana() - 25.f);
		Destroy();
	}
}

void APhlegethonEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}
