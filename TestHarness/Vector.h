#pragma once

#include "Math.h"

class Vector
{
public:
	/* Ctors -------------------------------------------------- */

	Vector() { ; }
	Vector(float inX, float inY, float inZ) :
		X(inX),
		Y(inY),
		Z(inZ)
	{}

	/** Operator Overloads ------------------------------------- */

	/** Evaluates if this vector is not equal to the user supplied Vector */
	bool operator!=(const Vector& inVect) const;

	/** Evaluates if this vector is equal to the user supplied Vector */
	bool operator==(const Vector& inVect) const;

	/** Adds this Vector and a user supplied Vector together and returns the new Vector result */
	Vector operator+(const Vector& inVect) const;

public:
	/** Public Interfaces -------------------------------------- */

	/** The magnitude of this Vector */
	const float Length();

	/** The Squared Magnitude of this Vector */
	const float LengthSquared();

	/** Perform a normalization on this Vector */
	void NormalizeVector();

	/** return Vector of this vector scaled by user supplied inVal */
	Vector ScaleVector(const float inVal) const;

	/** Get the Dot product of this Vector and a user supplied Vector */
	float DotProduct(const Vector& inVect) const;

	/** Calculate the dot product of two user supplied Vectors */
	static float DotProduct(const Vector& inVec1, const Vector& inVec2);

	/** Calculate the cross product */
	static Vector CrossProduct(const Vector& inVec1, const Vector& inVec2);


protected:
	/** protected Interfaces ----------------------------------- */
	// place here
private:
	/** Private Interfaces ------------------------------------- */
	// place here
public:
	/** Properties --------------------------------------------- */

	/** This Vector's X Component */
	float X;

	/** This Vector's Y Component */
	float Y;

	/** This Vector's Z Component */
	float Z;

	/** A zero valued Vector equal to Vector(0.0f,0.0f,0.0f) */
	static const Vector ZeroVector;

	/** A one valued Vector equal to Vector(1.0f,1.0f,1.0f) */
	static const Vector OneVector;

	/** A Vector representing Up equal to Vector(0.0f,0.0f,1.0f) */
	static const Vector UpVector;

	/** A Vector representing Forward equal to Vector(1.0f,0.0f,0.0f) */
	static const Vector ForwardVector;

	/** A Vector representing Right equal to Vector(0.0f,1.0f,0.0f) */
	static const Vector RightVector;

protected:
	/** protected properties ----------------------------------- */
	// place here
private:
	/** Private properties ------------------------------------- */
	// place here
};

/** Vector class implementations ------------------------------- */
inline bool Vector::operator!=(const Vector & inVect) const
{
	if (X != inVect.X ||
		Y != inVect.Y ||
		Z != inVect.Z)
	{
		return true;
	}
	return false;
}

inline bool Vector::operator==(const Vector & inVect) const
{
	if (X == inVect.X &&
		Y == inVect.Y &&
		Z == inVect.Z)
	{
		return true;
	}
	return false;
}

inline Vector Vector::operator+(const Vector& inVect) const
{
	return Vector(X + inVect.X, Y + inVect.Y, Z + inVect.Z);
}

inline const float Vector::Length()
{
	return Math::Sqrt(X * X + Y * Y + Z  *Z);
}

inline const float Vector::LengthSquared()
{
	return X * X + Y * Y + Z * Z;
}

inline void Vector::NormalizeVector()
{
	const float magnitute = Length();
	X = X / magnitute;
	Y = Y / magnitute;
	Z = Z / magnitute;
}

inline Vector Vector::ScaleVector(const float inVal) const
{
	return Vector(X*inVal, Y*inVal, Z*inVal);
}

inline float Vector::DotProduct(const Vector & inVect) const
{
	return (X * inVect.X + Y * inVect.Y + Z * inVect.Z);
}

inline float Vector::DotProduct(const Vector & inVec1, const Vector & inVec2)
{
	return (inVec1.X * inVec2.X + inVec1.Y * inVec2.Y + inVec1.Z * inVec2.Z);
}

inline Vector Vector::CrossProduct(const Vector & inVec1, const Vector & inVec2)
{
				 // XYZZY
	return Vector(/*X*/ inVec1.Y * inVec2.Z - inVec1.Z * inVec2.Y,
				  /*Y*/ inVec1.Z * inVec2.X - inVec1.X * inVec2.Z,
				  /*Z*/ inVec1.X * inVec2.Y - inVec1.Y * inVec2.X);
}


/** Left hand coordinate system implied here */
const Vector Vector::ZeroVector(0.0f, 0.0f, 0.0f);
const Vector Vector::OneVector(1.0f, 1.0f, 1.0f);
const Vector Vector::UpVector(0.0f, 0.0f, 1.0f);
const Vector Vector::ForwardVector(1.0f, 0.0f, 0.0f);
const Vector Vector::RightVector(0.0f, 1.0f, 0.0f);
