#pragma once
#include "Misc/Guid.h"
#include "Structs.generated.h"

USTRUCT(Blueprintable)
struct FLocation
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		float x;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		float y;
};

USTRUCT(Blueprintable)
struct FPredatorInstruction
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
	int destination;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
	int next_step;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
	bool contact;
};

USTRUCT(Blueprintable)
struct FOcclusions
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TArray<int> OcclusionIds;
};


USTRUCT(Blueprintable)
struct FCoordinates
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		int x;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		int y;
};

USTRUCT(Blueprintable)
struct FCell
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		int id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		int cell_type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		FCoordinates coordinates;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		FLocation location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		bool occluded;
};



USTRUCT(Blueprintable)
struct FExperimentState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		FLocation PreyLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		FLocation PredatorLocation;
};

USTRUCT(Blueprintable)
struct FServerCommand
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		FString Command;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		FString Content;
};



USTRUCT(Blueprintable)
struct FLocation3
{
	GENERATED_BODY()
public:
	FLocation3() = default;
	FLocation3(const FVector &location) {
		x = location.X;
		y = location.Y;
		z = location.Z;
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		float x;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		float y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		float z;
	bool operator ==(const FLocation3& other) {
		return x == other.x && y == other.y && z == other.z;
	}
	bool operator !=(const FLocation3& other) {
		return !(*(this) == other);
	}
};

USTRUCT(Blueprintable)
struct FRotation3
{
	GENERATED_BODY()
public:
	FRotation3() = default;
	FRotation3(const FRotator& rotator) {
		roll = rotator.Roll;
		pitch = rotator.Pitch;
		yaw = rotator.Yaw;
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		float roll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		float pitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		float yaw;
	bool operator ==(const FRotation3 &other) {
		return roll == other.roll && pitch == other.pitch && yaw == other.yaw;
	}
	bool operator !=(const FRotation3& other) {
		return !(*(this) == other);
	}
};


USTRUCT(Blueprintable)
struct FAgentState
{
	GENERATED_BODY()
public:
	FAgentState() = default;
	FAgentState(int frame, float time_stamp, const FString& AgentName, const FVector& location, const FRotator& rotator) :
	time_stamp(time_stamp),
	frame(frame),
	agent_name(AgentName),
	location(location),
	rotation(rotator){
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		float time_stamp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		int frame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		FString agent_name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		FLocation3 location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		FRotation3 rotation;
	bool operator ==(const FAgentState& other) {
		return location == other.location && rotation == other.rotation;
	}
	bool operator !=(const FAgentState& other) {
		return !(*(this) == other);
	}
};


USTRUCT(Blueprintable)
struct FStartEpisodeRequest
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
	int participant_id;
};

USTRUCT(Blueprintable)
struct FFinishEpisodeRequest
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Environment)
		int participant_id;
};


USTRUCT(Blueprintable)
struct FGetCellLocationsResponse
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TArray<FLocation> cell_locations;
};

USTRUCT(Blueprintable)
struct FStartEpisodeResponse
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TArray<int> occlusions;
	
	UPROPERTY()
		FLocation predator_spawn_location;
};

USTRUCT(Blueprintable)
struct FUpdateGhostMovementMessage
{
	GENERATED_BODY()
public:
	UPROPERTY()
	float forward;

	UPROPERTY()
	float rotation;
};


USTRUCT(Blueprintable)
struct FTransformation
{
	GENERATED_BODY()
public:
	UPROPERTY()
		float size;
	UPROPERTY()
		float rotation;
};


USTRUCT(Blueprintable)
struct FShape
{
	GENERATED_BODY()
public:
	UPROPERTY()
		int sides;
};


USTRUCT(Blueprintable)
struct FSpace
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FLocation center;

	UPROPERTY()
		FShape shape;

	UPROPERTY()
		FTransformation transformation;
};


USTRUCT(Blueprintable)
struct FWorldImplementation
{
	GENERATED_BODY()
public:
	UPROPERTY()
		TArray<FLocation> cell_locations;
	UPROPERTY()
		FSpace space;
	UPROPERTY()
		FTransformation cell_transformation;
};