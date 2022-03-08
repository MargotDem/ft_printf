#include "libft.h"

char	*ft_uitoa_base(unsigned int nb, int base)
{
	char			*nb_str;
	unsigned int	tmp;
    int				nb_size;

	tmp = nb;
	nb_size = 0;
	while (tmp)
	{
		tmp = tmp / (unsigned int)base;
		nb_size++;
	}
	nb_str = ft_strnew(nb_size);
	while (nb > 0)
	{
		tmp = nb % base;
		nb_size--;
		if (tmp <= 9)
			nb_str[nb_size] = 48 + tmp;
		else
			nb_str[nb_size] = 87 + tmp;
		nb = nb / base;
	}
	return (nb_str);
}