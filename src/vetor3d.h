
#ifndef VETOR3D_H
#define VETOR3D_H

#include <string>


/*
 * Classe vetor3d
 *
 * Esta classe foi criada pelos integrantes do grupo
 * para trabalhos de outras disciplinas.
 *
 * Ela implementa um trio de valores que pode ser usado
 * para contas na representação vetorial.
 * Para isso foram implementados vários operadores
 * aritméticos, como +, -, * e outros.
 */
template < class T >
class vetor3d {

	private:
		T X, Y, Z;

	public:
		vetor3d(): X(T(0)), Y(T(0)), Z(T(0)) {}

		vetor3d(const T & num): X(num), Y(num), Z(num) {}

		vetor3d(const T & x, const T & y, const T & z): X(x), Y(y), Z(z) {}

		vetor3d(const vetor3d< T > & vet): X(vet.X), Y(vet.Y), Z(vet.Z) {}

		T & operator[] (unsigned int i) {
			switch (i) {
				case 0: return X; break;
				case 1: return Y; break;
				case 2: return Z; break;
				default:
					throw std::string("índice do vetor é grande demais!");
					break;
			}
			return X;
		}

		T & x() {
			return X;
		}

		T & y() {
			return Y;
		}

		T & z() {
			return Z;
		}


		vetor3d< T > & operator= (const vetor3d< T > & vet) {
			X = vet.X;
			Y = vet.Y;
			Z = vet.Z;
			return *this;
		}

		vetor3d< T > operator* (const vetor3d< T > & outrovet) const {
			return vetor3d(X*outrovet.X, Y*outrovet.Y, Z*outrovet.Z);
		}

		vetor3d< T > & operator*= (const vetor3d< T > & outrovet) {
			X *= outrovet.X;
			Y *= outrovet.Y;
			Z *= outrovet.Z;
			return *this;
		}

		vetor3d< T > operator+ (const vetor3d< T > & outrovet) const {
			return vetor3d<T>(X+outrovet.X, Y+outrovet.Y, Z+outrovet.Z);
		}

		vetor3d< T > & operator+= (const vetor3d< T > & outrovet) {
			X += outrovet.X;
			Y += outrovet.Y;
			Z += outrovet.Z;
			return *this;
		}

		vetor3d< T > operator- (const vetor3d< T > & outrovet) const {
			return vetor3d<T>(X-outrovet.X, Y-outrovet.Y, Z-outrovet.Z);
		}

		vetor3d< T > & operator-= (const vetor3d< T > & outrovet) {
			X -= outrovet.X;
			Y -= outrovet.Y;
			Z -= outrovet.Z;
			return *this;
		}

		vetor3d< T > operator- () const {
			return vetor3d(-X, -Y, -Z);
		}

		T modulo() {
			return sqrt(X*X + Y*Y + Z*Z);
		}

};

#endif //VETOR3D_H

